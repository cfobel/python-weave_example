#include <blitz/array.h>

template <class T, int32_t ndim>
class Op {
public:
    void operator()(blitz::Array<T, ndim> a);
};


template <class T>
class Op<T, 1> {
public:
    void operator()(blitz::Array<T, 1> &a) {
        for(int32_t i = 0; i < a.size(); i++) {
            printf("a[%d]: %d\n", i, a(i));
        }
    }
};


template <class T>
class Op<T, 2> {
public:
    void operator()(blitz::Array<T, 2> &a) {
        const blitz::TinyVector<int, 2> &shape = a.shape();
        for(int32_t first_index = 0; first_index < shape[1]; first_index++) {
            for(int32_t second_index = 0; second_index < shape[0]; second_index++) {
                printf("a[%d][%d]: %d\n", first_index, second_index,
                        a(first_index, second_index));
            }
        }
    }
};


template <class T, int32_t ndim>
class BlitzExample {
public:
    void operator()(blitz::Array<T, ndim> a) {
        Op<T, ndim> op;
        op(a);
    }
};


