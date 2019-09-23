#define PY_SSIZE_T_CLEAN
#include <Python.h>

typedef struct {
    PyObject_HEAD
    /* Type-specific fields go here. */
} CustomObject;

PyDoc_STRVAR(Custom_doc, "Custom objects");

static PyType_Slot CustomType_slots[] = {
    {Py_tp_doc, Custom_doc},
    {Py_tp_new, PyType_GenericNew},
}

static PyType_Spec CustomType_spec = {
    "custom.Custom",
    sizeof(CustomObject),
    0,
    Py_TPFLAGS_DEFAULT,
    CustomType_slots,
};

static struct PyModuleDef custommodule = {
    PyModuleDef_HEAD_INIT,
    .m_name = "custom",
    .m_doc = "Example module that creates an extension type.",
    .m_size = -1,
};

PyMODINIT_FUNC
PyInit_custom(void)
{
    PyObject *m, *CustomType;

    m = PyModule_Create(&custommodule);
    if (m == NULL) {
        return NULL;
    }

    CustomType = PyType_FromSpec(&CustomType_spec);
    if (CustomType == NULL) {
        PY_DECREF(m);
        return NULL;
    }

    Py_INCREF(CustomType);
    if (PyModule_AddObject(m, "Custom", CustomType) < 0) {
        Py_DECREF(CustomType);
        PY_DECREF(m);
        return NULL;
    }

    return m;
}
