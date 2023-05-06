#pragma once

#include "pre_compiled_header.hpp"

#define TOBOT_ENUM(name, ...)                                                                                \
    /* Making sure the name is not empty*/                                                                   \
    static_assert(sizeof(#name) > 1, "A name for the generated enum class construct has to be specified");   \
    static_assert(sizeof(#__VA_ARGS__) > 1, "The enum needs at least a single enum constant");               \
    class name {                                                                                             \
        public:                                                                                              \
            enum Enum {                                                                                      \
                __VA_ARGS__,                                                                                 \
                COUNT                                                                                        \
            };                                                                                               \
            name(Enum value);                                                                                \
            name(name const & other);                                                                        \
            name(name && other) noexcept;                                                                    \
            auto operator=(name const & other) noexcept -> name const &;                                     \
            auto operator=(name && other) noexcept -> name const &;                                          \
            auto operator==(name const & other) const -> bool;                                               \
            auto operator!=(name const & other) const -> bool;                                               \
            [[nodiscard]] Enum get() const;                                                                  \
            auto ordinal() const -> std::size_t {                                                            \
                return static_cast<std::size_t>(m_value);                                                    \
            }                                                                                                \
            /* Can be evaluated at compile time*/                                                            \
            static consteval auto size() -> std::size_t {                                                    \
                return static_cast<std::size_t>(Enum::COUNT);                                                \
            }                                                                                                \
            static auto get(std::size_t index) -> Enum {                                                     \
                if (index >= size()) {                                                                       \
                    throw std::invalid_argument("Index out of bounds");                                      \
                }                                                                                            \
                return static_cast<Enum>(index);                                                             \
            }                                                                                                \
            static auto toString() -> std::string {                                                          \
                return #name;                                                                                \
            }                                                                                                \
            /* Retrieving all the values in the enum*/                                                       \
            static auto values() -> Enum const * const {                                                     \
                return s_values;                                                                             \
            }                                                                                                \
            /* We need to adapt our iterators to C++ 17 -                                                    \
             * https://www.fluentcpp.com/2018/05/08/std-iterator-deprecated/ */                              \
            class iterator : public std::iterator<std::input_iterator_tag, Enum, Enum, Enum const *, Enum> { \
                private:                                                                                     \
                    Enum beginn = static_cast<Enum>(0);                                                      \
                                                                                                             \
                public:                                                                                      \
                    explicit iterator(Enum beginn = static_cast<Enum>(0)) : beginn(beginn) {                 \
                    }                                                                                        \
                    auto operator++() -> iterator & {                                                        \
                        beginn = static_cast<Enum>(static_cast<std::size_t>(beginn) + 1);                    \
                        return *this;                                                                        \
                    }                                                                                        \
                    auto operator++(int) -> iterator {                                                       \
                        iterator tmp = *this;                                                                \
                        operator++();                                                                        \
                        return tmp;                                                                          \
                    }                                                                                        \
                    auto operator==(iterator const & other) const -> bool {                                  \
                        return beginn == other.beginn;                                                       \
                    }                                                                                        \
                    auto operator!=(iterator const & other) const -> bool {                                  \
                        return beginn != other.beginn;                                                       \
                    }                                                                                        \
                    auto operator*() const -> Enum {                                                         \
                        return beginn;                                                                       \
                    }                                                                                        \
            };                                                                                               \
            static iterator begin() {                                                                        \
                return iterator(static_cast<Enum>(0));                                                       \
            }                                                                                                \
            static iterator end() {                                                                          \
                return iterator(static_cast<Enum>(size()));                                                  \
            }                                                                                                \
                                                                                                             \
        private:                                                                                             \
            Enum m_value;                                                                                    \
            static inline Enum const s_values[] = {__VA_ARGS__};                                             \
    };                                                                                                       \
    [[nodiscard]] name::name(name::Enum value) : m_value(value) {                                            \
    }                                                                                                        \
    [[nodiscard]] name::name(name const & other) : m_value(other.m_value) {                                  \
    }                                                                                                        \
    [[nodiscard]] name::name(name && other) noexcept : m_value(std::move(other.m_value)) {                   \
    }                                                                                                        \
    [[nodiscard]] auto name::operator=(name const & other) noexcept -> name const & {                        \
        m_value = other.m_value;                                                                             \
        return *this;                                                                                        \
    }                                                                                                        \
    [[nodiscard]] auto name::operator=(name && other) noexcept -> name const & {                             \
        m_value = std::move(other.m_value);                                                                  \
        return *this;                                                                                        \
    }                                                                                                        \
    [[nodiscard]] auto name::operator==(name const & other) const->bool {                                    \
        return m_value == other.m_value;                                                                     \
    }                                                                                                        \
    [[nodiscard]] auto name::operator!=(name const & other) const->bool {                                    \
        return m_value != other.m_value;                                                                     \
    }                                                                                                        \
    [[nodiscard]] auto name::get() const->name::Enum {                                                       \
        return m_value;                                                                                      \
    }
