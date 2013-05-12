template <int32_t ndim>
class Example {
public:
    int32_t dump_dims(int32_t *shape) {
        int32_t length = 1;
        printf("dims: (");
        for(int i = 0; i < ndim; i++) {
            printf("%d, ", shape[i]);
            length *= shape[i];
        }
        printf(")\n");
        return length;
    }
    void operator()(int32_t *a, int32_t *shape);
};


template <>
void Example<1>::operator()(int32_t *a, int32_t *shape) {
    int32_t length = dump_dims(shape);
    for(int32_t i = 0; i < length; i++) {
        printf("a[%d]: %d\n", i, a[i]);
    }
}

template <>
void Example<2>::operator()(int32_t *a, int32_t *shape) {
    for(int32_t first_index = 0; first_index < shape[1]; first_index++) {
        for(int32_t second_index = 0; second_index < shape[0]; second_index++) {
            printf("a[%d][%d]: %d\n", first_index, second_index,
                    a[first_index * shape[1] + second_index]);
        }
    }
}
