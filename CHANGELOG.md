
## NAIAD INTERFACES

### [v0.2.15] (2024-09-06)

- 修改 AlgoControlMonitor

- ✨ feat: 新增 爬行能力参数


### [v0.2.14] (2024-08-20)

- ✨ feat: 新增 清除所有模块防拆告警服务

- ✨ feat: 新增 自动任务不能在水上180度调整的错误码

- ✨ feat: 适配822版本告警码配置

- SystemState 增加上次开机时间和关机时间

- ✨ feat: 添加机器人禁用的错误码

- 增加算法统计数据的消息类型

### [v0.2.13] (2024-08-13)

- 添加数据恢复时机器未贴附等状态

### [v0.2.12] (2024-07-26)

- 新增 泵压传感器和舵机告警

- 增加顶出电机监测状态

- 增加主控电源模块的消息定义PowerModuleState.msg

- 增加主控的状态定义

### [v0.2.11] (2024-07-19)

- ✨ feat: 新增 AIS告警码
- ✨ feat: 新增 AisData用于锚地数据
- ✨ feat: 新增 算法事件上报接口
- ✨ feat: 新增 锚地数据恢复失败错误码
- ✨ feat: 新增 算法ControlState
- ✨ feat: 新增 RobotState锚地异常状态
- ✨ feat: 新增 数据恢复数据新增锚地数据
- ✨ feat: 修改 动力电源故障告警等级降低


### [v0.2.10] (2024-07-01)
- AIS 的锚泊状态更改为5

### [v0.2.9] (2024-07-01)

- cpu状态，增加内存使用率，方便比较 磁盘信息，增加加载点及文件系统类型信息

- 增加一个KernelEvent.msg，用来定义来自内核的消息

- ✨ feat: 新增 电机3次重启失败告警码

- feat: 添加控制保护消息

- fix: 调整控制保护消息体

- feat: 增加舭龙骨保护消息体

- ✨ feat: 修改小轮异常所属模块

- ✨ feat: trace source auto switch alert

- ✨ feat: 更新大小轮异常告警码

- ✨ feat: 新增 任务进行中不允许设置机器人位置的错误码

- ✨ feat: 新增 告警增加算法检测的大小轮和FOG, 配置增加更多描述

- 📃 docs: 更新了alert.json


### [v0.2.8] (2024-06-14)

- 增加AIS相关接口


### [v0.2.7] (2024-05-31)

- 调整数据恢复相关接口定义

### [v0.2.6] (2024-05-26)

- MainControllerState.msg: 增加电机失效状态

- FogState.STATE_WRITE_ERROR -> FogState.STATE_COMMUNICATION_ERROR

- 增加数据恢复使用的消息定义，包括msg/RobotStoredState.msg, srv/AlgoDataRecovery.srv及相关的API返回值定义

### [v0.2.5] (2024-05-13)

- 全面整理ROBOT告警内容,增加导致告警级别到AlertCode.msg

- 增加alert_helper.py : 为了更方便的编写告警相关的脚本, 根据Skylar以前写的 generate_alert_code.py, 重写了这个脚本。这个脚本先解析配置文件生成告警对象, 然后根据这个告警, 可以实现多种功能。

### [v0.2.4] (2024-04-10)

- 作业控制消息，增加速度和转向控制禁用状态

- 增加一个慢速的深度传感器的消息，带水深数据

- 增加一些ApiState的返回值

### [v0.2.3] (2024-03-31)

- 增加两个电机告警，优化一些告警命名

### [v0.2.2] (2024-03-27)

- 增加docs/ApiGuide.md， 维护NAIAD所有ROS服务的参数及返回值 
  
- RobotOdometry.msg 增加frame的变量，反馈当前使用的Frame

- 优化TaskState.msg的定义，增加严格模式的专用的任务状态(SemiAutoTaskState.msg)
  
- SemiAutoTaskState.msg 使用统一的target_value 和 target_depth反馈当前目标坐标及深度

### [v0.2.1] (2024-03-18)

- 算法大重构
  
- 支持告警相关消息


### [v0.1.3] (2023-12-02)

- 告警系统接口更新: AlertEvent.msg, AlertCode.msg
  
- 告警脚本: script/generate_alert_code.py, 根据OS告警配置自动生成Robot端的Alertcode.msg
  
- RemoteControlState.msg增加未校准状态和原始值输出
  
- 更新：ApiState.msg

### [v0.1.2] (2023-11-22)

- 平台，业务及算法接口大规模优化

### [v0.1.1] (2023-08-24)

- 增加机架信息的消息定义ChasssisInfo.msg
  
- MainControllerState.msg 增加一个字段 actived，表示主控是否活动的
  
- 新增服务：MainControllerGetState.srv 返回当前主控的状态
  
- 新增服务: ChassisGetInfo.srv 返回当前机架的信息
  
- 新增服务: MainControllerUpgrade.srv 用来升级主控及外设固件
  
- 新增服务: MainControllerControl.srv 用来控制主控重启等
  
- 新增主题消息: MainControllerUpgradeState.srv 发布升级的状态

### [v0.1.0] 

- 初次版本定义
