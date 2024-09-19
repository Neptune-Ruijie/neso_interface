


#ifndef __NAIAD_API_STATE_HELPER_H__
#define __NAIAD_API_STATE_HELPER_H__

/**
 * @file api_state.hpp
 * @author Liu Chuansen (samuel@neptune-robotics.com)
 * @brief Api帮助
 * @version 0.1
 * @date 2024-03-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <sstream>
#include <sstream>
#include <fmt/format.h>

#include <rclcpp/rclcpp.hpp>
#include <naiad_interfaces/msg/api_state.hpp>


namespace naiad_interfaces {
namespace helper {

/// @brief 一个静态方法封装
class Api
{

public:

    // 实现一个更方便的返回API状态
    template<typename... Args>
    static naiad_interfaces::msg::ApiState ApiState(int status, fmt::format_string<Args...> fmt, Args &&... args) 
    {
        naiad_interfaces::msg::ApiState ret;
        ret.status = status;
        ret.message = fmt::format(fmt, std::forward<Args>(args)...); 
        return ret;
    }

    /// @brief 将状态字变成字串信息，只处理公共部分，后面的直接打值
    /// @param status 
    /// @return 
    static std::string ToString(int32_t status)    
    {
        switch (status) 
        {
            case naiad_interfaces::msg::ApiState::RET_SUCCESS: return "Success";
            case naiad_interfaces::msg::ApiState::RET_FAILED: return "Failed";
            case naiad_interfaces::msg::ApiState::RET_BUSY: return "Busy";
            case naiad_interfaces::msg::ApiState::RET_TIMEOUT: return "Operation Timeout";
            case naiad_interfaces::msg::ApiState::RET_NO_MEM: return "Memory Error";
            case naiad_interfaces::msg::ApiState::RET_NO_OBJECT: return "Object Not Exist";
            case naiad_interfaces::msg::ApiState::RET_NO_DEVICE: return "Device Not Exist";
            case naiad_interfaces::msg::ApiState::RET_NO_ACCESS: return "Not Accessible";
            case naiad_interfaces::msg::ApiState::RET_NO_INIT: return "Not Initialized";
            case naiad_interfaces::msg::ApiState::RET_INVALID_ADDRESS: return "Invalid Address";
            case naiad_interfaces::msg::ApiState::RET_INVALID_PARAMETER: return "Invalid Parameter";
            case naiad_interfaces::msg::ApiState::RET_INVALID_DATA: return "Invalid Data";
            case naiad_interfaces::msg::ApiState::RET_OVERFLOW: return "Overflow";
            case naiad_interfaces::msg::ApiState::RET_OVERSIZE: return "Oversize";
            case naiad_interfaces::msg::ApiState::RET_NOT_SUPPORTED: return "Function Not Supported";
            case naiad_interfaces::msg::ApiState::RET_NOT_AVAILABLE: return "Function Not Available";
            case naiad_interfaces::msg::ApiState::RET_IO_ERROR: return "IO Error";
            case naiad_interfaces::msg::ApiState::RET_TYPE_ERROR: return "Type Error";
            case naiad_interfaces::msg::ApiState::RET_CRC_ERROR: return "Checksum Error";
            case naiad_interfaces::msg::ApiState::RET_PROTOCOL_FAILED: return "Protocol Error";
            case naiad_interfaces::msg::ApiState::RET_INTERNAL_ERROR: return "Internal Error";
            case naiad_interfaces::msg::ApiState::RET_OBJECT_EXIST: return "Object Already Exists";
            case naiad_interfaces::msg::ApiState::RET_NOT_IMPLEMENTED: return "Not Implemented";
            case naiad_interfaces::msg::ApiState::RET_CANCEL: return "Cancelled";
            default: 
                return "StatusCode(" + std::to_string(status) + ")";
        }   
    }        

    /// @brief 将一个API返回状态打印出来
    /// @param ret 
    /// @return 
    static std::string ToString(naiad_interfaces::msg::ApiState const &ret) 
    {
        std::stringstream ss;
        ss << "{status:" << ret.status << ", message: '" << ret.message << "'}";
        return ss.str();
    }

};


} // helper
} // naiad_interfaces

#endif // __NAIAD_API_STATE_HELPER_H__
