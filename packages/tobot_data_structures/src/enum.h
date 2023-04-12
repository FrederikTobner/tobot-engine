#pragma once

#include "pre_compiled_header.h"

#define TOBOT_ENUM(name, ...)                                                                                \
    /* Making sure the name is not empty*/                                                                   \
    static_assert(sizeof(#name) > 1, "A name for the generated enum class construct has to be specified");   \
    class name {                                                                                             \
        public:                                                                                              \
            enum Enum {                                                                                      \
                __VA_ARGS__,                                                                                 \
                COUNT                                                                                        \
            };                                                                                               \
            name(Enum value);                                                                                \
            name(name const & other);                                                                        \
            name(name && other) noexcept;                                                                    \
            name const & operator=(name const & other) noexcept;                                             \
            name const & operator=(name && other) noexcept;                                                  \
            bool operator==(name const & other) const;                                                       \
            bool operator!=(name const & other) const;                                                       \
            [[nodiscard]] Enum get() const;                                                                  \
            std::size_t ordinal() const { return static_cast<std::size_t>(m_value); }                        \
            /* Can be evaluated at compile time*/                                                            \
            static consteval std::size_t size() { return static_cast<std::size_t>(Enum::COUNT); }            \
            static Enum get(std::size_t index) {                                                             \
                if (index >= size()) {                                                                       \
                    throw std::invalid_argument("Index out of bounds");                                      \
                }                                                                                            \
                return static_cast<Enum>(index);                                                             \
            }                                                                                                \
            static std::string toString() { return #name; }                                                  \
            /* Retrieving all the values in the enum*/                                                       \
            static Enum const * const values() { return s_values; }                                          \
            class iterator : public std::iterator<std::input_iterator_tag, Enum, Enum, Enum const *, Enum> { \
                private:                                                                                     \
                    Enum beginn = static_cast<Enum>(0);                                                      \
                                                                                                             \
                public:                                                                                      \
                    explicit iterator(Enum beginn = static_cast<Enum>(0)) : beginn(beginn) {}                \
                    iterator & operator++() {                                                                \
                        beginn = static_cast<Enum>(static_cast<std::size_t>(beginn) + 1);                    \
                        return *this;                                                                        \
                    }                                                                                        \
                    iterator operator++(int) {                                                               \
                        iterator tmp = *this;                                                                \
                        operator++();                                                                        \
                        return tmp;                                                                          \
                    }                                                                                        \
                    bool operator==(iterator const & other) const { return beginn == other.beginn; }         \
                    bool operator!=(iterator const & other) const { return beginn != other.beginn; }         \
                    Enum operator*() const { return beginn; }                                                \
            };                                                                                               \
            static iterator begin() { return iterator(static_cast<Enum>(0)); }                               \
            static iterator end() { return iterator(static_cast<Enum>(size())); }                            \
                                                                                                             \
        private:                                                                                             \
            Enum m_value;                                                                                    \
            static inline Enum const s_values[] = {__VA_ARGS__};                                             \
    };                                                                                                       \
    static_assert(name::COUNT > 0, "The enumeration must have at least one value");                          \
    name::name(name::Enum value) : m_value(value) {}                                                         \
    name::name(name const & other) : m_value(other.m_value) {}                                               \
    name::name(name && other) noexcept : m_value(std::move(other.m_value)) {}                                \
    name const & name::operator=(name const & other) noexcept {                                              \
        m_value = other.m_value;                                                                             \
        return *this;                                                                                        \
    }                                                                                                        \
    name const & name::operator=(name && other) noexcept {                                                   \
        m_value = std::move(other.m_value);                                                                  \
        return *this;                                                                                        \
    }                                                                                                        \
    bool name::operator==(name const & other) const { return m_value == other.m_value; }                     \
    bool name::operator!=(name const & other) const { return m_value != other.m_value; }                     \
    [[nodiscard]] name::Enum name::get() const { return m_value; }
