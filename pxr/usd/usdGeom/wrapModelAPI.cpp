//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdGeom/modelAPI.h"
#include "pxr/usd/usd/schemaBase.h"

#include "pxr/usd/sdf/primSpec.h"

#include "pxr/usd/usd/pyConversions.h"
#include "pxr/base/tf/pyAnnotatedBoolResult.h"
#include "pxr/base/tf/pyContainerConversions.h"
#include "pxr/base/tf/pyResultConversions.h"
#include "pxr/base/tf/pyUtils.h"
#include "pxr/base/tf/wrapTypeHelpers.h"

#include "pxr/external/boost/python.hpp"

#include <string>

PXR_NAMESPACE_USING_DIRECTIVE

using namespace pxr_boost::python;

namespace {

#define WRAP_CUSTOM                                                     \
    template <class Cls> static void _CustomWrapCode(Cls &_class)

// fwd decl.
WRAP_CUSTOM;

        
static UsdAttribute
_CreateModelDrawModeAttr(UsdGeomModelAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateModelDrawModeAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Token), writeSparsely);
}
        
static UsdAttribute
_CreateModelApplyDrawModeAttr(UsdGeomModelAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateModelApplyDrawModeAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Bool), writeSparsely);
}
        
static UsdAttribute
_CreateModelDrawModeColorAttr(UsdGeomModelAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateModelDrawModeColorAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float3), writeSparsely);
}
        
static UsdAttribute
_CreateModelCardGeometryAttr(UsdGeomModelAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateModelCardGeometryAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Token), writeSparsely);
}
        
static UsdAttribute
_CreateModelCardTextureXPosAttr(UsdGeomModelAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateModelCardTextureXPosAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Asset), writeSparsely);
}
        
static UsdAttribute
_CreateModelCardTextureYPosAttr(UsdGeomModelAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateModelCardTextureYPosAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Asset), writeSparsely);
}
        
static UsdAttribute
_CreateModelCardTextureZPosAttr(UsdGeomModelAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateModelCardTextureZPosAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Asset), writeSparsely);
}
        
static UsdAttribute
_CreateModelCardTextureXNegAttr(UsdGeomModelAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateModelCardTextureXNegAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Asset), writeSparsely);
}
        
static UsdAttribute
_CreateModelCardTextureYNegAttr(UsdGeomModelAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateModelCardTextureYNegAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Asset), writeSparsely);
}
        
static UsdAttribute
_CreateModelCardTextureZNegAttr(UsdGeomModelAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateModelCardTextureZNegAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Asset), writeSparsely);
}

static std::string
_Repr(const UsdGeomModelAPI &self)
{
    std::string primRepr = TfPyRepr(self.GetPrim());
    return TfStringPrintf(
        "UsdGeom.ModelAPI(%s)",
        primRepr.c_str());
}

struct UsdGeomModelAPI_CanApplyResult : 
    public TfPyAnnotatedBoolResult<std::string>
{
    UsdGeomModelAPI_CanApplyResult(bool val, std::string const &msg) :
        TfPyAnnotatedBoolResult<std::string>(val, msg) {}
};

static UsdGeomModelAPI_CanApplyResult
_WrapCanApply(const UsdPrim& prim)
{
    std::string whyNot;
    bool result = UsdGeomModelAPI::CanApply(prim, &whyNot);
    return UsdGeomModelAPI_CanApplyResult(result, whyNot);
}

} // anonymous namespace

void wrapUsdGeomModelAPI()
{
    typedef UsdGeomModelAPI This;

    UsdGeomModelAPI_CanApplyResult::Wrap<UsdGeomModelAPI_CanApplyResult>(
        "_CanApplyResult", "whyNot");

    class_<This, bases<UsdAPISchemaBase> >
        cls("ModelAPI");

    cls
        .def(init<UsdPrim>(arg("prim")))
        .def(init<UsdSchemaBase const&>(arg("schemaObj")))
        .def(TfTypePythonClass())

        .def("Get", &This::Get, (arg("stage"), arg("path")))
        .staticmethod("Get")

        .def("CanApply", &_WrapCanApply, (arg("prim")))
        .staticmethod("CanApply")

        .def("Apply", &This::Apply, (arg("prim")))
        .staticmethod("Apply")

        .def("GetSchemaAttributeNames",
             &This::GetSchemaAttributeNames,
             arg("includeInherited")=true,
             return_value_policy<TfPySequenceToList>())
        .staticmethod("GetSchemaAttributeNames")

        .def("_GetStaticTfType", (TfType const &(*)()) TfType::Find<This>,
             return_value_policy<return_by_value>())
        .staticmethod("_GetStaticTfType")

        .def(!self)

        
        .def("GetModelDrawModeAttr",
             &This::GetModelDrawModeAttr)
        .def("CreateModelDrawModeAttr",
             &_CreateModelDrawModeAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetModelApplyDrawModeAttr",
             &This::GetModelApplyDrawModeAttr)
        .def("CreateModelApplyDrawModeAttr",
             &_CreateModelApplyDrawModeAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetModelDrawModeColorAttr",
             &This::GetModelDrawModeColorAttr)
        .def("CreateModelDrawModeColorAttr",
             &_CreateModelDrawModeColorAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetModelCardGeometryAttr",
             &This::GetModelCardGeometryAttr)
        .def("CreateModelCardGeometryAttr",
             &_CreateModelCardGeometryAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetModelCardTextureXPosAttr",
             &This::GetModelCardTextureXPosAttr)
        .def("CreateModelCardTextureXPosAttr",
             &_CreateModelCardTextureXPosAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetModelCardTextureYPosAttr",
             &This::GetModelCardTextureYPosAttr)
        .def("CreateModelCardTextureYPosAttr",
             &_CreateModelCardTextureYPosAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetModelCardTextureZPosAttr",
             &This::GetModelCardTextureZPosAttr)
        .def("CreateModelCardTextureZPosAttr",
             &_CreateModelCardTextureZPosAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetModelCardTextureXNegAttr",
             &This::GetModelCardTextureXNegAttr)
        .def("CreateModelCardTextureXNegAttr",
             &_CreateModelCardTextureXNegAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetModelCardTextureYNegAttr",
             &This::GetModelCardTextureYNegAttr)
        .def("CreateModelCardTextureYNegAttr",
             &_CreateModelCardTextureYNegAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetModelCardTextureZNegAttr",
             &This::GetModelCardTextureZNegAttr)
        .def("CreateModelCardTextureZNegAttr",
             &_CreateModelCardTextureZNegAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))

        .def("__repr__", ::_Repr)
    ;

    _CustomWrapCode(cls);
}

// ===================================================================== //
// Feel free to add custom code below this line, it will be preserved by 
// the code generator.  The entry point for your custom code should look
// minimally like the following:
//
// WRAP_CUSTOM {
//     _class
//         .def("MyCustomMethod", ...)
//     ;
// }
//
// Of course any other ancillary or support code may be provided.
// 
// Just remember to wrap code in the appropriate delimiters:
// 'namespace {', '}'.
//
// ===================================================================== //
// --(BEGIN CUSTOM CODE)--

namespace {

static object
_GetExtentsHint(
        const UsdGeomModelAPI& self,
        const UsdTimeCode &time)
{
    VtVec3fArray extents;
    if (!self.GetExtentsHint(&extents, time)) {
        return object();
    }

    return object(extents);
}

static bool
_SetExtentsHint(
        UsdGeomModelAPI& self,
        const TfPyObjWrapper pyVal,
        const UsdTimeCode &timeVal)
{
    VtValue value = UsdPythonToSdfType(pyVal, SdfValueTypeNames->Float3Array);
    if (!value.IsHolding<VtVec3fArray>()) {
        TF_CODING_ERROR("Improper value for 'extentsHint' on %s",
                        UsdDescribe(self.GetPrim()).c_str());
        return false;
    }

    return self.SetExtentsHint(value.UncheckedGet<VtVec3fArray>(), timeVal);
}

WRAP_CUSTOM {
    _class
        .def("GetExtentsHint", &_GetExtentsHint,
                (arg("time")=UsdTimeCode::Default()))
        .def("SetExtentsHint", &_SetExtentsHint,
                (arg("extents"),
                 arg("time")=UsdTimeCode::Default()))
        .def("ComputeExtentsHint", &UsdGeomModelAPI::ComputeExtentsHint,
                (arg("bboxCache")))

        .def("GetExtentsHintAttr", &UsdGeomModelAPI::GetExtentsHintAttr)

        .def("GetConstraintTarget", &UsdGeomModelAPI::GetConstraintTarget)
        .def("CreateConstraintTarget", &UsdGeomModelAPI::CreateConstraintTarget)
        .def("GetConstraintTargets", &UsdGeomModelAPI::GetConstraintTargets,
            return_value_policy<TfPySequenceToList>())

        .def("ComputeModelDrawMode", &UsdGeomModelAPI::ComputeModelDrawMode,
            (arg("parentDrawMode")=TfToken()))
    ;
}

} // anonymous namespace 
