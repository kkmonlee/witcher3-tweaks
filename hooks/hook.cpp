#include "hook.h"

static HookBase *g_hookFunctions;

void HookBase::Register() {
    m_next = g_hookFunctions;
    g_hookFunctions = this;
}

void HookBase::RunAll() {
    for (auto func = g_hookFunctions; func; func = func->m_next) {
        func->Run();
    }
}

static RuntimeHook *g_runtimeHookFunctions;

void RuntimeHook::Register() {
    m_next = g_runtimeHookFunctions;
    g_runtimeHookFunctions = this;
}

void RuntimeHook::Run(const char *key) {
    for (auto func = g_runtimeHookFunctions; func; func = func->m_next) {
        if (func->m_key == key) {
            func->m_function();
        }
    }
}