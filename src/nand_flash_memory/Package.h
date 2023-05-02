#include <memory>
#include <vector>

typedef struct PackageData {
  uint64_t userData;
  uint64_t oob;
} PackageData;

class PackageComponent {
 public:
  PackageComponent(uint32_t id);
  virtual PackageData readPackageData(uint64_t ppa) = 0;
  virtual void writePackageData(uint64_t ppa, PackageData pkgData) = 0;
  virtual ~PackageComponent() = default;

  uint32_t getID() { return id; }

 protected:
  std::vector<std::unique_ptr<PackageComponent>> childs;

 private:
  uint32_t id;
};

class Page : public PackageComponent {
 public:
  Page(uint32_t id);
  PackageData readPackageData(uint64_t ppa) override;
  void writePackageData(uint64_t ppa, PackageData pkgData) override;
  ~Page() = default;

 private:
  PackageData packageData;
};

class Block : public PackageComponent {
 public:
  Block(uint32_t id, int numPages);
  PackageData readPackageData(uint64_t ppa) override;
  void writePackageData(uint64_t ppa, PackageData pkgData) override;
  ~Block() = default;
};

class Plane : public PackageComponent {
 public:
  Plane(uint32_t id, int numBlocks, int numPages);
  PackageData readPackageData(uint64_t ppa) override;
  void writePackageData(uint64_t ppa, PackageData pkgData) override;
  ~Plane() = default;
};

class Die : public PackageComponent {
 public:
  Die(uint32_t id, int numPlanes, int numBlocks, int numPages);
  PackageData readPackageData(uint64_t ppa) override;
  void writePackageData(uint64_t ppa, PackageData pkgData) override;
  ~Die() = default;
};

class Package : public PackageComponent {
 public:
  Package(uint32_t id, int numDies, int numPlanes, int numBlocks, int numPages);
  PackageData readPackageData(uint64_t ppa) override;
  void writePackageData(uint64_t ppa, PackageData pkgData) override;
  ~Package() = default;
};

class FlashMemory {
 public:
  FlashMemory(int numPkgs, int numDies, int numPlanes, int numBlocks,
              int numPages);

 private:
  std::vector<std::unique_ptr<PackageComponent>> pkgs;
};
