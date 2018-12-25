#ifndef Py_CPYTHON_OBJIMPL_H
#  error "this header file must not be included directly"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* This function returns the number of allocated memory blocks, regardless of size */
PyAPI_FUNC(Py_ssize_t) _Py_GetAllocatedBlocks(void);

/* Macros */
#ifdef WITH_PYMALLOC
PyAPI_FUNC(int) _PyObject_DebugMallocStats(FILE *out);
#endif


typedef struct {
    /* user context passed as the first argument to the 2 functions */
    void *ctx;

    /* allocate an arena of size bytes */
    void* (*alloc) (void *ctx, size_t size);

    /* free an arena */
    void (*free) (void *ctx, void *ptr, size_t size);
} PyObjectArenaAllocator;

/* Get the arena allocator. */
PyAPI_FUNC(void) PyObject_GetArenaAllocator(PyObjectArenaAllocator *allocator);

/* Set the arena allocator. */
PyAPI_FUNC(void) PyObject_SetArenaAllocator(PyObjectArenaAllocator *allocator);


PyAPI_FUNC(Py_ssize_t) _PyGC_CollectNoFail(void);
PyAPI_FUNC(Py_ssize_t) _PyGC_CollectIfEnabled(void);


/* Test if an object has a GC head */
#define PyObject_IS_GC(o) \
    (PyType_IS_GC(Py_TYPE(o)) \
     && (Py_TYPE(o)->tp_is_gc == NULL || Py_TYPE(o)->tp_is_gc(o)))

/* GC information is stored BEFORE the object structure. */
typedef struct {
    // Pointer to next object in the list.
    // 0 means the object is not tracked
    uintptr_t _gc_next;

    // Pointer to previous object in the list.
    // Lowest two bits are used for flags documented later.
    uintptr_t _gc_prev;
} PyGC_Head;

#define _Py_AS_GC(o) ((PyGC_Head *)(o)-1)

/* True if the object is currently tracked by the GC. */
#define _PyObject_GC_IS_TRACKED(o) (_Py_AS_GC(o)->_gc_next != 0)

/* True if the object may be tracked by the GC in the future, or already is.
   This can be useful to implement some optimizations. */
#define _PyObject_GC_MAY_BE_TRACKED(obj) \
    (PyObject_IS_GC(obj) && \
        (!PyTuple_CheckExact(obj) || _PyObject_GC_IS_TRACKED(obj)))


PyAPI_FUNC(PyObject *) _PyObject_GC_Malloc(size_t size);
PyAPI_FUNC(PyObject *) _PyObject_GC_Calloc(size_t size);


/* Test if a type supports weak references */
#define PyType_SUPPORTS_WEAKREFS(t) ((t)->tp_weaklistoffset > 0)

#define PyObject_GET_WEAKREFS_LISTPTR(o) \
    ((PyObject **) (((char *) (o)) + Py_TYPE(o)->tp_weaklistoffset))

#ifdef __cplusplus
}
#endif
