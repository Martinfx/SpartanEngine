/*
Copyright(c) 2016-2024 Panos Karabelas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is furnished
to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

namespace Spartan
{
    class Debugging
    {
    public:
        static void Initialize(const bool is_amd)
        {
            m_breadcrumbs_enabled = m_breadcrumbs_enabled ? is_amd : false;
        }

        static bool IsValidationLayerEnabled()              { return m_validation_layer_enabled; }
        static bool IsGpuAssistedValidationEnabled()        { return m_gpu_assisted_validation_enabled; }
        static bool IsGpuMarkingEnabled()                   { return m_gpu_marking_enabled; }
        static bool IsGpuTimingEnabled()                    { return m_gpu_timing_enabled; }
        static void SetGpuTimingEnabled(const bool enabled) { m_gpu_timing_enabled = enabled; }
        static bool IsRenderdocEnabled()                    { return m_renderdoc_enabled; }
        static bool IsShaderOptimizationEnabled()           { return m_shader_optimization_enabled; }
        static bool IsLoggingToFileEnabled()                { return m_logging_to_file_enabled; }
        static bool IsBreadcrumbsEnabled()                  { return m_breadcrumbs_enabled; }

    private:
        inline static bool m_validation_layer_enabled        = false; // enables vulkan validation, high cpu overhead per draw
        inline static bool m_gpu_assisted_validation_enabled = false; // gpu-based validation, significant cpu and gpu cost
        inline static bool m_logging_to_file_enabled         = false; // logs to file, high cpu cost due to disk i/o
        inline static bool m_breadcrumbs_enabled             = false; // tracks gpu crashes and writes info into breadcrumbs.txt, minimal overhead - will be ignored for non-amd gpus
        inline static bool m_renderdoc_enabled               = false; // integrates renderdoc, high cpu overhead from api wrapping
        inline static bool m_gpu_marking_enabled             = true;  // negligible cost
        inline static bool m_gpu_timing_enabled              = true;  // negligible cost
        inline static bool m_shader_optimization_enabled     = true;  // high cost when off
    };
}
