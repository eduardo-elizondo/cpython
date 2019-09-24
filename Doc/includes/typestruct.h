typedef struct{
    /* For printing, in format "<module>.<name>" */
    const char* name;

    /* For allocation */
    int basicsize;
    int itemsize;

    /* Flags to define presence of optional/expanded features */
    unsigned int flags;

    /* For defining all the function slots in the type */
    PyType_Slot *slots;
} PyType_Spec;

typedef struct{
    /* The slot identifier, in the form "Py_<slot_name>" */
    int slot;

    /* The function pointer */
    void *pfunc;
} PyType_Slot;

/* Type Slot List: */

/* Documentation string */
Py_tp_doc

/* Methods to implement standard operations */
Py_tp_alloc
Py_tp_base
Py_tp_bases
Py_tp_call
Py_tp_clear
Py_tp_dealloc
Py_tp_del
Py_tp_descr_get
Py_tp_descr_set
Py_tp_finalize
Py_tp_free
Py_tp_getattr
Py_tp_getattro
Py_tp_getset
Py_tp_hash
Py_tp_init
Py_tp_is_gc
Py_tp_iter
Py_tp_iternext
Py_tp_members
Py_tp_methods
Py_tp_new
Py_tp_repr
Py_tp_richcompare
Py_tp_setattr
Py_tp_setattro
Py_tp_str
Py_tp_traverse

/* Mapping methods */
Py_mp_ass_subscript
Py_mp_length
Py_mp_subscript

/* Number methods */
Py_nb_absolute
Py_nb_add
Py_nb_and
Py_nb_bool
Py_nb_divmod
Py_nb_float
Py_nb_floor_divide
Py_nb_index
Py_nb_inplace_add
Py_nb_inplace_and
Py_nb_inplace_floor_divide
Py_nb_inplace_lshift
Py_nb_inplace_matrix_multiply
Py_nb_inplace_multiply
Py_nb_inplace_or
Py_nb_inplace_power
Py_nb_inplace_remainder
Py_nb_inplace_rshift
Py_nb_inplace_subtract
Py_nb_inplace_true_divide
Py_nb_inplace_xor
Py_nb_int
Py_nb_invert
Py_nb_lshift
Py_nb_matrix_multiply
Py_nb_multiply
Py_nb_negative
Py_nb_or
Py_nb_positive
Py_nb_power
Py_nb_remainder
Py_nb_rshift
Py_nb_subtract
Py_nb_true_divide
Py_nb_xor

/* Sequence methods */
Py_sq_ass_item
Py_sq_concat
Py_sq_contains
Py_sq_inplace_concat
Py_sq_inplace_repeat
Py_sq_item
Py_sq_length
Py_sq_repeat

/* Async methods */
Py_am_aiter
Py_am_anext
Py_am_await
