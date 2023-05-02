#pragma once

#include "tobot_math.h"

namespace Tobot::Core {

    class Transform2D {

        public:
            Transform2D();
            Transform2D(const Math::Vector2D<float> & position, float rotation, const Math::Vector2D<float> & scale);

            /// @brief Gets the position of the object
            /// @return The position of the object
            Math::Vector2D<float> getPosition() const;

            /// @brief Gets the rotation of the object
            /// @return The rotation of the object
            float getRotation() const;

            /// @brief Gets the scale of the object
            /// @return The scale of the object
            Math::Vector2D<float> getScale() const;

        private:
            // The position of the object
            Math::Vector2D<float> m_Position;
            // The rotation of the object
            float m_Rotation;
            // The scale of the object
            Math::Vector2D<float> m_Scale;
    };
} // namespace Tobot::Core