#pragma once
#include "Executor.hpp"
//提供Execute和Query的具体实现
namespace adas
{
class Executorimpl final : public Executor//final表示该类不能被其他类继承
{
public:
    //构造函数 初始化Pose
    explicit Executorimpl(const Pose& pose) noexcept;//explicit表示只能用显式构造函数
    
    ~Executorimpl() noexcept = default;//默认析构函数

    // 禁用拷贝构造函数和拷贝赋值操作符
    Executorimpl(const Executorimpl&) = delete;
    Executorimpl& operator=(const Executorimpl&) = delete;

public:
    void Execute(const std::string& command) noexcept override;//重写且不抛出异常
    Pose Query(void) const noexcept override;

private:
    Pose pose;
};

}  // namespace adas
