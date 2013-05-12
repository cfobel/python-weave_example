class Example {
public:
    void operator()(int32_t *a, int32_t ndim, int32_t *shape) {
        int32_t length = 1;
        printf("dims: (");
        for(int i = 0; i < ndim; i++) {
            printf("%d, ", shape[i]);
            length *= shape[i];
        }
        printf(")\n");
        for(int i = 0; i < length; i++) {
            printf("a[%d]: %d\n", i, a[i]);
        }
    }
};
