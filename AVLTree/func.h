struct TAVLTree {
    int Height;
    int Value;
    struct TAVLTree* Left;
    struct TAVLTree* Right;
};

struct TMemory {
    struct TAVLTree* Memory;
    size_t start;
    size_t Size;
};

struct TAVLTree* AddValue(struct TAVLTree* tree, struct TMemory* memory, long long value);
struct TAVLTree* Balance(struct TAVLTree* tree);
int Difference(struct TAVLTree* tree);
int GetHeight(struct TAVLTree* tree);
int Max(int a, int b);
struct TAVLTree* LeftSmallRotate(struct TAVLTree* tree);
struct TAVLTree* RightSmallRotate(struct TAVLTree* tree);
struct TAVLTree* RightBigRotate(struct TAVLTree* tree);
struct TAVLTree* LeftBigRotate(struct TAVLTree* tree);
struct TAVLTree* MakeNode(struct TMemory* memory, long long value);
void* MyMalloc(struct TMemory* memory, int size);
