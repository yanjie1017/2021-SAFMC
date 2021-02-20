
"use strict";

let TimesyncStatus = require('./TimesyncStatus.js');
let CamIMUStamp = require('./CamIMUStamp.js');
let WaypointList = require('./WaypointList.js');
let WheelOdomStamped = require('./WheelOdomStamped.js');
let ActuatorControl = require('./ActuatorControl.js');
let OpticalFlowRad = require('./OpticalFlowRad.js');
let PositionTarget = require('./PositionTarget.js');
let DebugValue = require('./DebugValue.js');
let HilGPS = require('./HilGPS.js');
let ManualControl = require('./ManualControl.js');
let WaypointReached = require('./WaypointReached.js');
let VehicleInfo = require('./VehicleInfo.js');
let LogEntry = require('./LogEntry.js');
let AttitudeTarget = require('./AttitudeTarget.js');
let HilActuatorControls = require('./HilActuatorControls.js');
let BatteryStatus = require('./BatteryStatus.js');
let HilStateQuaternion = require('./HilStateQuaternion.js');
let LandingTarget = require('./LandingTarget.js');
let ESCInfo = require('./ESCInfo.js');
let Waypoint = require('./Waypoint.js');
let EstimatorStatus = require('./EstimatorStatus.js');
let HilSensor = require('./HilSensor.js');
let Thrust = require('./Thrust.js');
let MountControl = require('./MountControl.js');
let RCIn = require('./RCIn.js');
let OverrideRCIn = require('./OverrideRCIn.js');
let CompanionProcessStatus = require('./CompanionProcessStatus.js');
let ParamValue = require('./ParamValue.js');
let RadioStatus = require('./RadioStatus.js');
let GlobalPositionTarget = require('./GlobalPositionTarget.js');
let CommandCode = require('./CommandCode.js');
let HomePosition = require('./HomePosition.js');
let RTKBaseline = require('./RTKBaseline.js');
let ExtendedState = require('./ExtendedState.js');
let FileEntry = require('./FileEntry.js');
let Trajectory = require('./Trajectory.js');
let OnboardComputerStatus = require('./OnboardComputerStatus.js');
let ADSBVehicle = require('./ADSBVehicle.js');
let StatusText = require('./StatusText.js');
let Param = require('./Param.js');
let RTCM = require('./RTCM.js');
let ESCStatus = require('./ESCStatus.js');
let Vibration = require('./Vibration.js');
let ESCInfoItem = require('./ESCInfoItem.js');
let HilControls = require('./HilControls.js');
let Altitude = require('./Altitude.js');
let ESCStatusItem = require('./ESCStatusItem.js');
let PlayTuneV2 = require('./PlayTuneV2.js');
let VFR_HUD = require('./VFR_HUD.js');
let GPSRTK = require('./GPSRTK.js');
let RCOut = require('./RCOut.js');
let GPSRAW = require('./GPSRAW.js');
let LogData = require('./LogData.js');
let State = require('./State.js');
let Mavlink = require('./Mavlink.js');

module.exports = {
  TimesyncStatus: TimesyncStatus,
  CamIMUStamp: CamIMUStamp,
  WaypointList: WaypointList,
  WheelOdomStamped: WheelOdomStamped,
  ActuatorControl: ActuatorControl,
  OpticalFlowRad: OpticalFlowRad,
  PositionTarget: PositionTarget,
  DebugValue: DebugValue,
  HilGPS: HilGPS,
  ManualControl: ManualControl,
  WaypointReached: WaypointReached,
  VehicleInfo: VehicleInfo,
  LogEntry: LogEntry,
  AttitudeTarget: AttitudeTarget,
  HilActuatorControls: HilActuatorControls,
  BatteryStatus: BatteryStatus,
  HilStateQuaternion: HilStateQuaternion,
  LandingTarget: LandingTarget,
  ESCInfo: ESCInfo,
  Waypoint: Waypoint,
  EstimatorStatus: EstimatorStatus,
  HilSensor: HilSensor,
  Thrust: Thrust,
  MountControl: MountControl,
  RCIn: RCIn,
  OverrideRCIn: OverrideRCIn,
  CompanionProcessStatus: CompanionProcessStatus,
  ParamValue: ParamValue,
  RadioStatus: RadioStatus,
  GlobalPositionTarget: GlobalPositionTarget,
  CommandCode: CommandCode,
  HomePosition: HomePosition,
  RTKBaseline: RTKBaseline,
  ExtendedState: ExtendedState,
  FileEntry: FileEntry,
  Trajectory: Trajectory,
  OnboardComputerStatus: OnboardComputerStatus,
  ADSBVehicle: ADSBVehicle,
  StatusText: StatusText,
  Param: Param,
  RTCM: RTCM,
  ESCStatus: ESCStatus,
  Vibration: Vibration,
  ESCInfoItem: ESCInfoItem,
  HilControls: HilControls,
  Altitude: Altitude,
  ESCStatusItem: ESCStatusItem,
  PlayTuneV2: PlayTuneV2,
  VFR_HUD: VFR_HUD,
  GPSRTK: GPSRTK,
  RCOut: RCOut,
  GPSRAW: GPSRAW,
  LogData: LogData,
  State: State,
  Mavlink: Mavlink,
};
