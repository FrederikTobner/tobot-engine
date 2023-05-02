#pragma once

#include "tobot_math.h"

namespace Tobot::Core {

    class Transform2D {

        public:
            /// @brief Creates a new Transform2D object with default values
            Transform2D();

            /// @brief Creates a new Transform2D object with the given values
            /// @param position The position of the object
            /// @param rotation The rotation of the object
            /// @param scale The scale of the object
            Transform2D(const Math::Vector2D<float> & position, float rotation, const Math::Vector2D<float> & scale);

            /// @brief Deconstructor of the Transform2D object
            ~Transform2D();

            /// @brief Gets the position of the object
            /// @return The position of the object
            auto getPosition() const -> Math::Vector2D<float>;

            /// @brief Gets the rotation of the object
            /// @return The rotation of the object
            auto getRotation() const -> float;

            /// @brief Gets the scale of the object
            /// @return The scale of the object
            auto getScale() const -> Math::Vector2D<float>;

            /// @brief Moves the transform in the direction and distance of translation
            /// @param translation The translation vector
            auto translate(const Math::Vector2D<float> & translation) -> void;

        private:
            // The position of the object
            Math::Vector2D<float> m_Position;
            // The rotation of the object
            float m_Rotation;
            // The scale of the object
            Math::Vector2D<float> m_Scale;
    };
} // namespace Tobot::Core