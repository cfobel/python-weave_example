"""
This module provides 1/2-D FFTs for functions taken on the interval
n = [-N/2, ..., N/2-1] in all transformed directions. This is accomplished
quickly by making a change of variables in the DFT expression, leading to
multiplication of exp(+/-jPIk) * DFT{exp(+/-jPIn) * [n]}. Take notice that
BOTH your input and output arrays will be arranged on the negative-to-positive
interval. To take regular FFTs, shifting can be turned off.
"""
import numpy as N
from scipy.weave import inline
import os
from os.path import join, split
from numpy.distutils.system_info import get_info
from path import path

example_code = \
r"""
int32_t *i = (int32_t *)a;


if(ndim == 2) {
    BlitzExample<int32_t, 2> t;
    blitz::Array<int32_t, 2> A(a, blitz::shape(shape[0], shape[1]),
                               blitz::neverDeleteData);
    t(A);
} else if(ndim == 1) {
    BlitzExample<int32_t, 1> t;
    blitz::Array<int32_t, 1> A(a, shape[0], blitz::neverDeleteData);
    t(A);
}
"""

def example(a):
    ndim = N.int(a.ndim)
    shape = N.array(a.shape, dtype=N.int32)
    inline(example_code, ['a', 'shape', 'ndim'],
           headers=['<iostream>', '<stdint.h>', '"example.hpp"',
                    '<blitz/array.h>'],
           include_dirs=[os.getcwd()],
           compiler='gcc', force=1)


def go():
    d = N.arange(100, dtype=N.int32)
    d.shape = 10, 10
    example(d)
    d = N.arange(100, dtype=N.int32)
    example(d)


if __name__ == '__main__':
    go()
