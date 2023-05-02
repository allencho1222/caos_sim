#include <cassert>
#include <memory>
#include <vector>

#include "Package.h"

PackageComponent::PackageComponent(uint32_t id) : id(id) {}

Page::Page(uint32_t id) : PackageComponent(id) {}

PackageData Page::readPackageData(uint64_t ppa) {
  // auto pageID;
  // assert(pageID == getID());
  return packageData;
}

void Page::writePackageData(uint64_t ppa, PackageData pkgData) {
  // auto pageID;
  // assert(pageID == getID());
  packageData = pkgData;
}

Block::Block(uint32_t id, int numPages) : PackageComponent(id) {
  for (int p = 0; p < numPages; ++p) {
    childs.push_back(std::make_unique<Page>(p));
  }
}

PackageData Block::readPackageData(uint64_t ppa) {
  return childs[0]->readPackageData(ppa);
}

void Block::writePackageData(uint64_t ppa, PackageData pkgData) {
  childs[0]->writePackageData(ppa, pkgData);
}

Plane::Plane(uint32_t id, int numBlocks, int numPages) : PackageComponent(id) {
  for (int b = 0; b < numBlocks; ++b) {
    childs.push_back(std::make_unique<Block>(b, numPages));
  }
}

PackageData Plane::readPackageData(uint64_t ppa) {
  return childs[0]->readPackageData(ppa);
}

void Plane::writePackageData(uint64_t ppa, PackageData pkgData) {
  childs[0]->writePackageData(ppa, pkgData);
}

Die::Die(uint32_t id, int numPlanes, int numBlocks, int numPages)
    : PackageComponent(id) {
  for (int p = 0; p < numPlanes; ++p) {
    childs.push_back(std::make_unique<Plane>(p, numBlocks, numPages));
  }
}

PackageData Die::readPackageData(uint64_t ppa) {
  return childs[0]->readPackageData(ppa);
}

void Die::writePackageData(uint64_t ppa, PackageData pkgData) {
  childs[0]->writePackageData(ppa, pkgData);
}

Package::Package(uint32_t id, int numDies, int numPlanes, int numBlocks,
                 int numPages)
    : PackageComponent(id) {
  for (int d = 0; d < numDies; ++d) {
    childs.push_back(std::make_unique<Die>(d, numPlanes, numBlocks, numPages));
  }
}

PackageData Package::readPackageData(uint64_t ppa) {
  return childs[0]->readPackageData(ppa);
}

void Package::writePackageData(uint64_t ppa, PackageData pkgData) {
  childs[0]->writePackageData(ppa, pkgData);
}

FlashMemory::FlashMemory(int numPkgs, int numDies, int numPlanes, int numBlocks,
                         int numPages) {
  for (int p = 0; p < numPkgs; ++p) {
    pkgs.push_back(
        std::make_unique<Package>(p, numDies, numPlanes, numBlocks, numPages));
  }
}
