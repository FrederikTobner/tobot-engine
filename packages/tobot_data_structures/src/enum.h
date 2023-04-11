#pragma once

#include "pre_compiled_header.h"

#define TOBOT_ENUM(name, ...)                                                                      \
    class name {                                                                                   \
        public:                                                                                    \
            enum Value {                                                                           \
                __VA_ARGS__,                                                                       \
                COUNT,                                                                             \
                UNDEFIENED                                                                         \
            };                                                                                     \
            name(Value value);                                                                     \
            operator Value() const;                                                                \
            bool operator==(const name & other) const;                                             \
            bool operator!=(const name & other) const;                                             \
            static constexpr std::size_t size() { return static_cast<std::size_t>(Value::COUNT); } \
            static Value * values() {                                                              \
                Value * result = (Value *)malloc(sizeof(Value) * size());                          \
                if (!result)                                                                       \
                    return nullptr;                                                                \
                for (std::size_t i = 0; i < size(); ++i) {                                         \
                    result[i] = static_cast<Value>(i);                                             \
                }                                                                                  \
                return result;                                                                     \
            }                                                                                      \
            static std::string toString() { return #name; }                                        \
            int ordinal() const { return m_value; }                                                \
            static Value get(std::size_t index) {                                                  \
                if (index >= size())                                                               \
                    return Value::UNDEFIENED;                                                      \
                return static_cast<Value>(index);                                                  \
            }                                                                                      \
                                                                                                   \
        private:                                                                                   \
            Value m_value;                                                                         \
    };                                                                                             \
    name::name(Value value) : m_value(value) {}                                                    \
    name::operator Value() const { return m_value; }                                               \
    bool name::operator==(const name & other) const { return m_value == other.m_value; }           \
    bool name::operator!=(const name & other) const { return m_value != other.m_value; }
