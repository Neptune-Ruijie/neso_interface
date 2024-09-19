

#ifndef __NAIAD_TASK_COMMAND_H__
#define __NAIAD_TASK_COMMAND_H__

/**
 * @file task_command.hpp
 * @author Liu Chuansen (samuel@neptune-robotics.com)
 * @brief task_command服务的帮助类实现
 * @version 0.1
 * @date 2024-02-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <sstream>
#include <rclcpp/rclcpp.hpp>

#include <naiad_interfaces/msg/task_mode.hpp>
#include <naiad_interfaces/msg/task_speed_gear.hpp>
#include <naiad_interfaces/msg/task_command_action.hpp>
#include <naiad_interfaces/srv/task_command.hpp>

namespace naiad_interfaces {
namespace helper {



/// @brief 一个静态方法封装
class TaskCommand 
{

public:

    /// 定深/定宽的命令
    struct AdjustData
    {
        uint32_t sequence;
        float    adjust_value;
    };

    /// @brief 返回任务命令的ACTION名称
    /// @param action 
    /// @return 
    static std::string ActionName(uint8_t action)    
    {
        static const std::map<uint8_t, std::string> action_names = 
        {
            {naiad_interfaces::msg::TaskCommandAction::SET_TASK_MODE,       "SetTaskMode"},
            {naiad_interfaces::msg::TaskCommandAction::SET_ADJUST_DEPTH,    "SetAdjustFixedDepth"},
            {naiad_interfaces::msg::TaskCommandAction::SET_ADJUST_WIDTH,    "SetAdjustFixedWidth"},
            {naiad_interfaces::msg::TaskCommandAction::SET_SPEED_GEAR,      "SetSpeedGear"},
        };

        auto it = action_names.find(action);
        return (it != action_names.end()) ? it->second : "N/A";                      
    }

    /// @brief 返回任务类型名称
    /// @param mode 
    /// @return 
    static std::string TaskModeName(uint8_t mode)
    {
        static const std::map<uint8_t, std::string> task_modes = 
        {
            //{naiad_interfaces::msg::TaskMode::TASK_MODE_DISABLED,       "TaskDisabled"},
            {naiad_interfaces::msg::TaskMode::TASK_MODE_MANUAL,         "TaskManual"},
            {naiad_interfaces::msg::TaskMode::TASK_MODE_SEMI_AUTO,      "TaskSemiAuto"},
            {naiad_interfaces::msg::TaskMode::TASK_MODE_AUTO_HORIZONTAL_POSE,           "TaskAutoHorizontalPose"},
        };

        auto it = task_modes.find(mode);
        return (it != task_modes.end()) ? it->second : "N/A";              
    }

    /// @brief 返回速度档位设置
    /// @param level 
    /// @return 
    static std::string SpeedGearLevelName(uint8_t level)
    {
        static const std::map<uint8_t, std::string> speed_levels = 
        {
            {naiad_interfaces::msg::TaskSpeedGear::LEVEL_VERY_SLOW,    "VerySlow"},
            {naiad_interfaces::msg::TaskSpeedGear::LEVEL_SLOW,         "Slow"},
            {naiad_interfaces::msg::TaskSpeedGear::LEVEL_ONE,          "One"},
            {naiad_interfaces::msg::TaskSpeedGear::LEVEL_TWO,          "Two"},
            {naiad_interfaces::msg::TaskSpeedGear::LEVEL_THREE,        "Three"},
            {naiad_interfaces::msg::TaskSpeedGear::LEVEL_FOUR,         "Four"},
        };

        auto it = speed_levels.find(level);
        return (it != speed_levels.end()) ? it->second : "N/A";              
    }    
    

    /// @brief 转换为字串
    /// @param command 
    /// @return 
    static std::string ToString(msg::TaskCommandAction const & command)
    {     
        std::stringstream ss;   
        ss << "Action:" << ActionName(command.action);

        switch(command.action) 
        {
            case naiad_interfaces::msg::TaskCommandAction::SET_TASK_MODE:
                ss << " Mode: " << TaskModeName(GetTaskMode(command));
                break;
            case naiad_interfaces::msg::TaskCommandAction::SET_SPEED_GEAR:
                ss << " Level: " << SpeedGearLevelName(GetSpeedGearLevel(command));
                break;
            case naiad_interfaces::msg::TaskCommandAction::SET_ADJUST_DEPTH:
            case naiad_interfaces::msg::TaskCommandAction::SET_ADJUST_WIDTH:    
                AdjustData data = GetAdjustData(command);        
                ss << " Sequence: " << data.sequence;
                ss << " Adjust: " << data.adjust_value;
                break;
        } 

        return ss.str();
    }


    /// @brief 获取任务模式
    /// @param command 
    /// @return 
    static uint8_t GetTaskMode(msg::TaskCommandAction const & command)
    {
        uint8_t mode = 0xff;
        if (!command.integer_values.empty()){
            mode = command.integer_values[0];
        }
        return mode;
    }

    /// @brief 获取速度档位值
    /// @param command 
    /// @return 
    static uint8_t GetSpeedGearLevel(msg::TaskCommandAction const & command)
    {
        uint8_t level = 0;
        if (!command.integer_values.empty()){
            level = command.integer_values[0];
        }
        return level;
    }

    /// @brief 获取定深操作的参数
    /// @param command 
    /// @return 
    static AdjustData GetAdjustData(msg::TaskCommandAction const & command)
    {
        AdjustData data = { };

        data.sequence = command.integer_values.empty() ? 0 : command.integer_values[0];
        data.adjust_value = command.float_values.empty() ? 0.0f : command.float_values[0];

        return data;
    }



    /// @brief 创建一个修改任务模式
    /// @param mode see:: TaskMode
    /// @return 
    static msg::TaskCommandAction SetTaskMode(uint8_t mode) 
    {
        msg::TaskCommandAction command;
        command.action = msg::TaskCommandAction::SET_TASK_MODE;
        command.integer_values[0] = mode;

        return command;
    }

    /// @brief 创建一个设定定宽命令
    /// @param sequence 操作序列号，用来同步业务和算法
    /// @param adjust_width 定宽值
    /// @return 
    static msg::TaskCommandAction SetAdjustFixedWidth(uint32_t sequence, float adjust_width)
    {
        msg::TaskCommandAction command;
        command.action = msg::TaskCommandAction::SET_ADJUST_WIDTH;
        command.integer_values[0] = sequence;
        command.float_values[0] = adjust_width;

        return command;
    }

    /// @brief 创建一个设定定深命令
    /// @param sequence 操作序列号，用来同步业务和算法
    /// @param adjust_depth 定宽值    
    /// @return 
    static msg::TaskCommandAction SetAdjustFixedDepth(uint32_t sequence, float adjust_depth)
    {
        msg::TaskCommandAction command;
        command.action = msg::TaskCommandAction::SET_ADJUST_DEPTH;
        command.integer_values[0] = sequence;
        command.float_values[0] = adjust_depth;

        return command;
    }

    /// @brief 创建一个档位设定命令
    /// @param level 
    /// @return 
    static msg::TaskCommandAction SetSpeedGearLevel(uint8_t level)
    {
        msg::TaskCommandAction command;
        command.action = msg::TaskCommandAction::SET_SPEED_GEAR;
        command.integer_values[0] = level;

        return command;        
    }
};








}
}

#endif // __NAIAD_TASK_COMMAND_H__
