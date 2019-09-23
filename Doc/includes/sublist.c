#define PY_SSIZE_T_CLEAN
#include <Python.h>

typedef struct {
    PyListObject list;
    int state;
} SubListObject;

static PyObject *
SubList_increment(SubListObject *self, PyObject *unused)
{
    self->state++;
    return PyLong_FromLong(self->state);
}

static PyMethodDef SubList_methods[] = {
    {"increment", (PyCFunction) SubList_increment, METH_NOARGS,
     PyDoc_STR("increment state counter")},
    {NULL},
};

static int
SubList_init(SubListObject *self, PyObject *args, PyObject *kwds)
{
    if (PyList_Type.tp_init((PyObject *) self, args, kwds) < 0)
        return -1;
    self->state = 0;
    return 0;
}

PyDoc_STRVAR(SubList_doc, "SubList objects");

static PyType_Slot SubListType_slots[] = {
    {Py_tp_doc, SubList_doc},
    {Py_tp_init, SubList_init},
    {Py_tp_methods, SubList_methods},
}

static PyType_Spec SubListType_spec = {
    "sublist.SubList",
    sizeof(SubListObject),
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    SubListType_slots,
};

static PyModuleDef sublistmodule = {
    PyModuleDef_HEAD_INIT,
    .m_name = "sublist",
    .m_doc = "Example module that creates an extension type.",
    .m_size = -1,
};

PyMODINIT_FUNC
PyInit_sublist(void)
{
    PyObject *m, *bases, *SubListType;

    m = PyModule_Create(&sublistmodule);
    if (m == NULL) {
        return NULL;
    }

    bases = PyTuple_Pack(1, &PyList_Type);
    SubListType = PyType_FromSpecWithBases(&SubListType_spec, bases);
    Py_DECREF(bases);
    if (SubListType == NULL) {
        PY_DECREF(m);
        return NULL;
    }

    Py_INCREF(SubListType);
    if (PyModule_AddObject(m, "SubList", SubListType) < 0) {
        Py_DECREF(SubListType);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}
