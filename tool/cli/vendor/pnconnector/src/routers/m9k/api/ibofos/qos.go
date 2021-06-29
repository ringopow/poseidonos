package ibofos

import (
    "pnconnector/src/routers/m9k/model"
)

func QosCreateVolumePolicy(xrId string, param interface{}) (model.Request, model.Response, error) {
	return qosSender(xrId, param, "QOSCREATEVOLUMEPOLICY")
}

func QosResetVolumePolicy(xrId string, param interface{}) (model.Request, model.Response, error) {
	return qosSender(xrId, param, "QOSRESETVOLUMEPOLICY")
}

func QosListPolicies(xrId string, param interface{}) (model.Request, model.Response, error) {
	return qosSender(xrId, param, "QOSLISTPOLICIES")
}
func qosSender(xrId string, param interface{}, command string) (model.Request, model.Response, error) {
    return Requester{xrId, param, model.QosParam{}}.Send(command)
}

