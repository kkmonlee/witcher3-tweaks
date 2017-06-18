#pragma once

#include <string>

class HookBase {
private:
    HookBase* m_next;

public:
    HookBase() {
        Register();
    }

    virtual void Run() = 0;

    static void RunAll();
    void Register();
};

class Hook : public HookBase {
private:
    void(*m_function)();

public:
    Hook(void(*function)()) {
        m_function = function;
    }

    virtual void Run() {
        m_function();
    }
};

class RuntimeHook {
private:
    void(*m_function)();
    std::string m_key;

    RuntimeHook *m_next;

public:
    RuntimeHook(const char *key, void(*function)()) {
        m_key = key;
        m_function = function;

        Register();
    }

    static void Run(const char *key);
    void Register();
}