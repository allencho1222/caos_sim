#include "Package.h"

#include <cassert>
#include <memory>
#include <vector>

PackageComponent::PackageComponent(uint32_t id) : id(id) {}

Page::Page(uint32_t id) : PackageComponent(id) {}

PageData Page::ReadPage(uint64_t ppa) {
  // auto pageID;
  // assert(pageID == getID());
  return page_data_;
}

void Page::WritePage(uint64_t ppa, PageData page_data) {
  // auto pageID;
  // assert(pageID == getID());
  page_data_ = page_data;
}

Block::Block(uint32_t id, int num_pages) : PackageComponent(id) {
  for (int p = 0; p < num_pages; ++p) {
    childs.push_back(std::make_unique<Page>(p));
  }
}

PageData Block::ReadPage(uint64_t ppa) { return childs[0]->ReadPage(ppa); }

void Block::WritePage(uint64_t ppa, PageData page_data) {
  childs[0]->WritePage(ppa, page_data);
}

Plane::Plane(uint32_t id, int num_blocks, int num_pages)
    : PackageComponent(id) {
  for (int b = 0; b < num_blocks; ++b) {
    childs.push_back(std::make_unique<Block>(b, num_pages));
  }
}

PageData Plane::ReadPage(uint64_t ppa) { return childs[0]->ReadPage(ppa); }

void Plane::WritePage(uint64_t ppa, PageData page_data) {
  childs[0]->WritePage(ppa, page_data);
}

Die::Die(uint32_t id, int num_planes, int num_blocks, int num_pages)
    : PackageComponent(id) {
  for (int p = 0; p < num_planes; ++p) {
    childs.push_back(std::make_unique<Plane>(p, num_blocks, num_pages));
  }
}

PageData Die::ReadPage(uint64_t ppa) { return childs[0]->ReadPage(ppa); }

void Die::WritePage(uint64_t ppa, PageData page_data) {
  childs[0]->WritePage(ppa, page_data);
}

Package::Package(uint32_t id, int num_dies, int num_planes, int num_blocks,
                 int num_pages)
    : PackageComponent(id) {
  for (int d = 0; d < num_dies; ++d) {
    childs.push_back(
        std::make_unique<Die>(d, num_planes, num_blocks, num_pages));
  }
}

PageData Package::ReadPage(uint64_t ppa) { return childs[0]->ReadPage(ppa); }

void Package::WritePage(uint64_t ppa, PageData page_data) {
  childs[0]->WritePage(ppa, page_data);
}

FlashMemory::FlashMemory(int num_pkgs, int num_dies, int num_planes,
                         int num_blocks, int num_pages) {
  for (int p = 0; p < num_pkgs; ++p) {
    pkgs.push_back(std::make_unique<Package>(p, num_dies, num_planes,
                                             num_blocks, num_pages));
  }
}
