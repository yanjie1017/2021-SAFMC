
"use strict";

let ParamGet = require('./ParamGet.js')
let LogRequestEnd = require('./LogRequestEnd.js')
let MountConfigure = require('./MountConfigure.js')
let LogRequestList = require('./LogRequestList.js')
let CommandTriggerInterval = require('./CommandTriggerInterval.js')
let CommandLong = require('./CommandLong.js')
let CommandBool = require('./CommandBool.js')
let ParamPush = require('./ParamPush.js')
let FileRename = require('./FileRename.js')
let FileChecksum = require('./FileChecksum.js')
let CommandVtolTransition = require('./CommandVtolTransition.js')
let WaypointPull = require('./WaypointPull.js')
let SetMode = require('./SetMode.js')
let FileWrite = require('./FileWrite.js')
let SetMavFrame = require('./SetMavFrame.js')
let FileTruncate = require('./FileTruncate.js')
let FileClose = require('./FileClose.js')
let ParamPull = require('./ParamPull.js')
let FileRead = require('./FileRead.js')
let CommandHome = require('./CommandHome.js')
let VehicleInfoGet = require('./VehicleInfoGet.js')
let LogRequestData = require('./LogRequestData.js')
let FileRemoveDir = require('./FileRemoveDir.js')
let WaypointSetCurrent = require('./WaypointSetCurrent.js')
let CommandInt = require('./CommandInt.js')
let StreamRate = require('./StreamRate.js')
let MessageInterval = require('./MessageInterval.js')
let ParamSet = require('./ParamSet.js')
let FileList = require('./FileList.js')
let FileRemove = require('./FileRemove.js')
let CommandTriggerControl = require('./CommandTriggerControl.js')
let CommandTOL = require('./CommandTOL.js')
let WaypointPush = require('./WaypointPush.js')
let WaypointClear = require('./WaypointClear.js')
let FileMakeDir = require('./FileMakeDir.js')
let FileOpen = require('./FileOpen.js')

module.exports = {
  ParamGet: ParamGet,
  LogRequestEnd: LogRequestEnd,
  MountConfigure: MountConfigure,
  LogRequestList: LogRequestList,
  CommandTriggerInterval: CommandTriggerInterval,
  CommandLong: CommandLong,
  CommandBool: CommandBool,
  ParamPush: ParamPush,
  FileRename: FileRename,
  FileChecksum: FileChecksum,
  CommandVtolTransition: CommandVtolTransition,
  WaypointPull: WaypointPull,
  SetMode: SetMode,
  FileWrite: FileWrite,
  SetMavFrame: SetMavFrame,
  FileTruncate: FileTruncate,
  FileClose: FileClose,
  ParamPull: ParamPull,
  FileRead: FileRead,
  CommandHome: CommandHome,
  VehicleInfoGet: VehicleInfoGet,
  LogRequestData: LogRequestData,
  FileRemoveDir: FileRemoveDir,
  WaypointSetCurrent: WaypointSetCurrent,
  CommandInt: CommandInt,
  StreamRate: StreamRate,
  MessageInterval: MessageInterval,
  ParamSet: ParamSet,
  FileList: FileList,
  FileRemove: FileRemove,
  CommandTriggerControl: CommandTriggerControl,
  CommandTOL: CommandTOL,
  WaypointPush: WaypointPush,
  WaypointClear: WaypointClear,
  FileMakeDir: FileMakeDir,
  FileOpen: FileOpen,
};
