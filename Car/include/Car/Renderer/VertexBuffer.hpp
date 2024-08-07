#pragma once

#include "Car/Core/Core.hpp"
#include "Car/Renderer/Buffer.hpp"
#include "Car/Renderer/BufferLayout.hpp"

namespace Car {
    class VertexBuffer {
    public:
        virtual ~VertexBuffer() = default;

        virtual void bind() const = 0;
        // for debug purposes
        virtual void unbind() const = 0;

        virtual void updateData(void* data, uint32_t size, uint32_t offset) = 0;

        virtual const BufferLayout& getLayout() const = 0;

        virtual uint32_t getSize() const = 0;
        virtual Buffer::Usage getUsage() const = 0;

        static Ref<VertexBuffer> Create(void* data, uint32_t size, BufferLayout layout, Buffer::Usage usage);
    };
} // namespace Car
