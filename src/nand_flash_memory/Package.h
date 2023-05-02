#include <memory>
#include <vector>

typedef struct PageData {
  uint64_t userData;
  uint64_t oob;
} PageData;

class PackageComponent {
 public:
  PackageComponent(uint32_t id);
  virtual PageData ReadPage(uint64_t ppa) const = 0;
  virtual void WritePage(uint64_t ppa, PageData page_data) = 0;
  virtual ~PackageComponent() = default;

  uint32_t getID() const { return id; }

 protected:
  std::vector<std::unique_ptr<PackageComponent>> childs;

 private:
  uint32_t id;
};

class Page : public PackageComponent {
 public:
  Page(uint32_t id);
  PageData ReadPage(uint64_t ppa) const override;
  void WritePage(uint64_t ppa, PageData page_data) override;
  ~Page() = default;

 private:
  PageData page_data_;
};

class Block : public PackageComponent {
 public:
  Block(uint32_t id, int num_pages);
  PageData ReadPage(uint64_t ppa) const override;
  void WritePage(uint64_t ppa, PageData page_data) override;
  ~Block() = default;
};

class Plane : public PackageComponent {
 public:
  Plane(uint32_t id, int num_blocks, int num_pages);
  PageData ReadPage(uint64_t ppa) const override;
  void WritePage(uint64_t ppa, PageData page_data) override;
  ~Plane() = default;
};

class Die : public PackageComponent {
 public:
  Die(uint32_t id, int num_planes, int num_blocks, int num_pages);
  PageData ReadPage(uint64_t ppa) const override;
  void WritePage(uint64_t ppa, PageData page_data) override;
  ~Die() = default;
};

class Package : public PackageComponent {
 public:
  Package(uint32_t id, int num_dies, int num_planes, int num_blocks,
          int num_pages);
  PageData ReadPage(uint64_t ppa) const override;
  void WritePage(uint64_t ppa, PageData page_data) override;
  ~Package() = default;
};

class FlashMemory {
 public:
  FlashMemory(int num_pkgs, int num_dies, int num_planes, int num_blocks,
              int num_pages);

 private:
  std::vector<std::unique_ptr<PackageComponent>> pkgs;
};
