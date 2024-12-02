#include "Executorimpl.hpp"
namespace adas{

    Executor* Executor::NewExecutor(const Pose& pose) noexcept
    {
        //返回一个Executorlmpl类型的指针
        //std::nothrow确保在内存分配失败时返回nullptr而不是抛出异常
        return new (std::nothrow) Executorimpl(pose);
    }
    // Executorlmpl 构造函数实现
    Executorimpl::Executorimpl(const Pose& pose) noexcept : pose(pose)
    {
        // 任何额外的初始化代码可以放在这里（如果有需要）
    }

    // Executorlmpld的构造函数
    void Executorimpl::Execute(const std::string& commands) noexcept
    {
        // 定义一个方向数组来表示 'N', 'E', 'S', 'W'
        const char directions[] = {'N', 'E', 'S', 'W'};
        int current_heading = -1;

        // 查找当前朝向在方向数组中的位置
        for (int i = 0; i < 4; ++i) {
            if (pose.heading == directions[i]) {
                current_heading = i;
                break;
            }
        }

        for (auto order = commands.begin(); order < commands.end(); order++) {
            if (*order == 'M') {  // 前进
                if (pose.heading == 'N') {
                    pose.y++;
                } else if (pose.heading == 'S') {
                    pose.y--;
                } else if (pose.heading == 'E') {
                    pose.x++;
                } else if (pose.heading == 'W') {
                    pose.x--;
                }
            } else if (*order == 'L') {  // 左转
                // 方向编号减 1，然后对 4 取模，确保结果在 0-3 范围内
                current_heading = (current_heading - 1 + 4) % 4;
                pose.heading = directions[current_heading];
            } else if (*order == 'R') {  // 右转
                // 方向编号加 1，然后对 4 取模，确保结果在 0-3 范围内
                current_heading = (current_heading + 1) % 4;
                pose.heading = directions[current_heading];
            }
        }
    }

    Pose Executorimpl::Query()const noexcept
    {
        return pose;
    }








}