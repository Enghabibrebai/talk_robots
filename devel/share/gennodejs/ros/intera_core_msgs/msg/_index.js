
"use strict";

let IODeviceStatus = require('./IODeviceStatus.js');
let CollisionAvoidanceState = require('./CollisionAvoidanceState.js');
let JointLimits = require('./JointLimits.js');
let HeadState = require('./HeadState.js');
let IONodeConfiguration = require('./IONodeConfiguration.js');
let NavigatorState = require('./NavigatorState.js');
let DigitalOutputCommand = require('./DigitalOutputCommand.js');
let EndpointStates = require('./EndpointStates.js');
let JointCommand = require('./JointCommand.js');
let CollisionDetectionState = require('./CollisionDetectionState.js');
let AnalogIOStates = require('./AnalogIOStates.js');
let RobotAssemblyState = require('./RobotAssemblyState.js');
let AnalogOutputCommand = require('./AnalogOutputCommand.js');
let DigitalIOStates = require('./DigitalIOStates.js');
let InteractionControlCommand = require('./InteractionControlCommand.js');
let IOComponentStatus = require('./IOComponentStatus.js');
let IOComponentConfiguration = require('./IOComponentConfiguration.js');
let NavigatorStates = require('./NavigatorStates.js');
let HomingCommand = require('./HomingCommand.js');
let HomingState = require('./HomingState.js');
let AnalogIOState = require('./AnalogIOState.js');
let EndpointNamesArray = require('./EndpointNamesArray.js');
let URDFConfiguration = require('./URDFConfiguration.js');
let IOStatus = require('./IOStatus.js');
let HeadPanCommand = require('./HeadPanCommand.js');
let SEAJointState = require('./SEAJointState.js');
let DigitalIOState = require('./DigitalIOState.js');
let IODataStatus = require('./IODataStatus.js');
let CameraSettings = require('./CameraSettings.js');
let IOComponentCommand = require('./IOComponentCommand.js');
let IONodeStatus = require('./IONodeStatus.js');
let InteractionControlState = require('./InteractionControlState.js');
let IODeviceConfiguration = require('./IODeviceConfiguration.js');
let CameraControl = require('./CameraControl.js');
let EndpointState = require('./EndpointState.js');
let CalibrationCommandActionGoal = require('./CalibrationCommandActionGoal.js');
let CalibrationCommandAction = require('./CalibrationCommandAction.js');
let CalibrationCommandActionFeedback = require('./CalibrationCommandActionFeedback.js');
let CalibrationCommandGoal = require('./CalibrationCommandGoal.js');
let CalibrationCommandActionResult = require('./CalibrationCommandActionResult.js');
let CalibrationCommandResult = require('./CalibrationCommandResult.js');
let CalibrationCommandFeedback = require('./CalibrationCommandFeedback.js');

module.exports = {
  IODeviceStatus: IODeviceStatus,
  CollisionAvoidanceState: CollisionAvoidanceState,
  JointLimits: JointLimits,
  HeadState: HeadState,
  IONodeConfiguration: IONodeConfiguration,
  NavigatorState: NavigatorState,
  DigitalOutputCommand: DigitalOutputCommand,
  EndpointStates: EndpointStates,
  JointCommand: JointCommand,
  CollisionDetectionState: CollisionDetectionState,
  AnalogIOStates: AnalogIOStates,
  RobotAssemblyState: RobotAssemblyState,
  AnalogOutputCommand: AnalogOutputCommand,
  DigitalIOStates: DigitalIOStates,
  InteractionControlCommand: InteractionControlCommand,
  IOComponentStatus: IOComponentStatus,
  IOComponentConfiguration: IOComponentConfiguration,
  NavigatorStates: NavigatorStates,
  HomingCommand: HomingCommand,
  HomingState: HomingState,
  AnalogIOState: AnalogIOState,
  EndpointNamesArray: EndpointNamesArray,
  URDFConfiguration: URDFConfiguration,
  IOStatus: IOStatus,
  HeadPanCommand: HeadPanCommand,
  SEAJointState: SEAJointState,
  DigitalIOState: DigitalIOState,
  IODataStatus: IODataStatus,
  CameraSettings: CameraSettings,
  IOComponentCommand: IOComponentCommand,
  IONodeStatus: IONodeStatus,
  InteractionControlState: InteractionControlState,
  IODeviceConfiguration: IODeviceConfiguration,
  CameraControl: CameraControl,
  EndpointState: EndpointState,
  CalibrationCommandActionGoal: CalibrationCommandActionGoal,
  CalibrationCommandAction: CalibrationCommandAction,
  CalibrationCommandActionFeedback: CalibrationCommandActionFeedback,
  CalibrationCommandGoal: CalibrationCommandGoal,
  CalibrationCommandActionResult: CalibrationCommandActionResult,
  CalibrationCommandResult: CalibrationCommandResult,
  CalibrationCommandFeedback: CalibrationCommandFeedback,
};
