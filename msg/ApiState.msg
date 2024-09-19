#定义API操作状态
int32 status
string message

#错误状态码
int32 RET_SUCCESS = 0             # 操作成功    
int32 RET_FAILED = 1              # 操作失败
int32 RET_BUSY = 2                # 对象/设备忙
int32 RET_TIMEOUT = 3             # 操作超时
int32 RET_NO_MEM = 4              # 内存错误/不可用
int32 RET_NO_OBJECT = 5           # 指定的对象不存在
int32 RET_NO_DEVICE = 6           # 指定的设备不存在
int32 RET_NO_ACCESS = 7           # 不可访问
int32 RET_NO_INIT = 8             # 未初始化
int32 RET_INVALID_ADDRESS = 9     # 无效的地址
int32 RET_INVALID_PARAMETER = 10  # 无效的参数
int32 RET_INVALID_DATA = 11       # 无效的数据
int32 RET_OVERFLOW = 12           # 溢出
int32 RET_OVERSIZE = 13           # 过载
int32 RET_NOT_SUPPORTED = 14      # 功能不支持
int32 RET_NOT_AVAILABLE = 15      # 功能/接口不可用 
int32 RET_IO_ERROR = 16           # IO错误
int32 RET_TYPE_ERROR = 17         # 类型错误
int32 RET_CRC_ERROR = 18          # CRC校验错误
int32 RET_PROTOCOL_FAILED = 19    # 协议错误
int32 RET_INTERNAL_ERROR = 20     # 内部错误
int32 RET_OBJECT_EXIST = 21       # 对象已存在
int32 RET_NOT_IMPLEMENTED = 22    # 未实现
int32 RET_CANCEL = 23             # 用户取消

#通用API请求
int32 RET_INVALID_REQUEST = 30   # API协议不一致
int32 RET_SERVICE_OFFLINE = 31   # 请求服务不在线
int32 RET_DISABLED = 32   # 机器人禁用中，请联系管理员

## 0-99 for public state 
## 100-199 for system and platform 
## others are free for use, please register it here
## algo team will use [200 - 299]
## cyberbot<skylar> use [300-500]

#系统通用
int32 RET_FILE_NOT_EXIST = 100   # 文件打开失败或不存在
int32 RET_ROBOT_ERROR = 101      # 机器人存在错误
int32 RET_TASK_IS_ACTIVED = 102  # 任务已在活动状态

#升级状态
int32 RET_UPGRADING = 190                # 正在升级中 
int32 RET_UPGRADE_OBJECT_OFFLINE = 191   # 升级对象不在线
int32 RET_UPGRADE_START_FAILED = 192     # 升级启动失败

#算法相关
int32 RET_COORDINATE_TRANSFORM_PITCH_INVALID = 200        # CoordinateTransform.srv 坐标转换时，机头不水平
int32 RET_COORDINATE_TRANSFORM_ROLL_INVALID = 201         # CoordinateTransform.srv 坐标转换时，没有在直板
int32 RET_CHANGE_TASK_FORBIDDEN = 202                     # 有任务正在进行，不允许转换task，需要先停止任务，再进行转换
int32 RET_TASK_CONTROL_NOT_AUTO_TASK = 203                # 现在不是自动任务，是半自动或者手动
int32 RET_NO_FOG_DATA = 204                               # Robot state error_status 没有FOG数据,FOG未启动
int32 RET_NO_MOTION_DATA = 205                            # Robot state error_status 没有轮子数据
int32 RET_NO_DEPTH_DATA = 206                             # Robot state error_status 没有深度数据
int32 RET_NO_TASK_PARAMPER = 207                          # TaskParameter.msg 没有任务作业参数


# 数据恢复
int32 RET_DATA_RECOVERY_DB_DATA_INVALID = 210     # 数据恢复失败，DB数据无效
int32 RET_DATA_RECOVERY_DATA_OVER_TIME = 211       # 数据恢复失败，数据时间超时
int32 RET_DATA_RECOVERY_PARAMS_UNPAIR = 212   # 数据恢复失败，作业参数不一致
int32 RET_DATA_RECOVERY_OPS_ID_UNPAIR = 213       # 数据恢复失败，作业任务不一致
int32 RET_DATA_RECOVERY_SHIP_UNPAIR = 214       # 数据恢复失败，船舶不一致
int32 RET_DATA_RECOVERY_OPERATION_SCENE_UNPAIR = 215       # 数据恢复失败，作业场景不一致
int32 RET_DATA_RECOVERY_OUTER_BOARD_UNPAIR = 216       # 数据恢复失败，外侧板不一致
int32 RET_DATA_RECOVERY_CURRENT_BOARD_UNPAIR = 217       # 数据恢复失败，当前板不一致
int32 RET_DATA_RECOVERY_ROBOT_MOVING = 218       # 数据恢复失败，机器已移动，无法恢复
int32 RET_DATA_RECOVERY_FOG_NOT_ALIGN = 219       # 数据恢复失败，FOG未对准完成，无法恢复
int32 RET_DATA_RECOVERY_GPS_UNPAIR = 220       # 数据恢复失败，经纬度不一致
int32 RET_DATA_RECOVERY_NO_ANCHOR_DATA = 221       # 数据恢复失败，无锚地数据


# 机器人系统 [300-500]

## RobotCalibration [300-350]
# FOG对准请求失败原因
int32 RET_FOG_UNNORMAL = 301            # MQTT请求对准时返回，表示：FOG异常中，现在无法对准，请解决异常后再重试
int32 RET_FOG_ALIGNING = 302            # MQTT请求对准时返回，表示：FOG正在对准中，无需重新对准
int32 RET_ROBOT_MOVING = 303            # MQTT请求对准时返回，表示：机器人运动中，无法对准，请停下机器人进行对准
int32 RET_GIMBAL_LOCK = 304             # MQTT请求对准时返回，表示：机器位姿指天指地，请调整机器人姿态后再对准
int32 RET_PUMP_OPENING = 305            # MQTT请求对准时返回，表示：水泵打开，无法对准，请关闭水泵

# FOG对准失败原因
int32 RET_FOG_LOCATION_NOT_EQUAL = 310  # 对准失败，经纬度不一致, 请检查作业设置
int32 RET_FOG_LOW_QUALITY = 311         # 对准失败，质量差, 请重试
int32 RET_FOG_ALIGN_TIMEOUT = 312         # 对准失败，超时, 请重试
## 向FOG节点请求对准, 返回超时或失败
int32 RET_FOG_ALIGN_TASK_REJECT_BY_FOG = 313       # 请求FOG对准失败, 请重试
int32 RET_FOG_ALIGN_TASK_REQUEST_TIMEOUT = 314      # 请求FOG对准超时, 请重试


# 坐标转换
int32 RET_ALIGN_NOT_SUCCESS = 320       # 坐标转换失败, FOG未完成对准

# 标定
int32 RET_NO_TRANSFORM = 330          # 未完成坐标转换
int32 RET_MARK_POSE_ON_SEMI_AUTO_ADJUSTING = 331          # 正在定深/定宽中, 无法设置机器人位置
int32 RET_MARK_POSE_ON_AUTO_HORIZONTAL_POSING = 332          # 自动调整姿态中, 无法设置机器人位置

# 设备控制
int32 RET_CONTROL_FAILED_WHEN_ROBOT_MOVING = 340  # 控制失败, 机器人运动中, 无法处理某些指令
int32 RET_CONTROL_FAILED_WHEN_AUTOTASK_RUNNING = 341  # 控制失败, 自动化任务进行中, 无法处理某些指令

# 通用自动化任务异常 [400-450]
## 1. 算法自动任务相关
int32 RET_SIMPLE_AUTO_TASK_REJECT_BY_ALGO = 400       # 请求算法自动调平失败, 请重试
int32 RET_SIMPLE_AUTO_TASK_STATE_ERROR = 401          # 自动调平任务状态异常, 请重试
int32 RET_SIMPLE_AUTO_TASK_REQUEST_TIMEOUT = 402      # 请求算法自动调平超时, 请重试
int32 RET_SIMPLE_AUTO_TASK_TIMEOUT = 403              # 自动调平任务超时失败, 请重试
int32 RET_SIMPLE_AUTO_TASK_NO_TURN_AROUND = 404              # 自动调平任务失败, 水面上不能180度掉头


## 2.遥控器打断
int32 RET_RC_DISCONNECT     = 410       # 自动调平任务失败, 遥控器异常状态
int32 RET_RC_INTERRUPT      = 411       # 自动调平任务失败, 被遥控器打断 
int32 RET_LIFTER_CTRL_FAILED = 412       # 自动调平任务失败, 舵机无法升起, 请解除禁足或升起舵机
int32 RET_FORBIDDEN_MOVE    = 413       # 自动调平任务失败, 机器禁足, 请先解除禁足