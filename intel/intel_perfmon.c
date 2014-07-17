/*
 * Copyright © 2014 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <stdio.h>
#include <stdint.h>

#include "i915_drm.h"
#include "i915_perfmon.h"
#include <xf86drm.h>

#include "intel_perfmon.h"

int
drm_intel_perfmon_wait_irq(int fd, struct drm_i915_perfmon_wait_irqs *wait_irqs)
{

	struct drm_i915_perfmon perfmon_ioctl;
	int ret;

	perfmon_ioctl.op = I915_PERFMON_WAIT_BUFFER_IRQS;
	perfmon_ioctl.data.wait_irqs.timeout = wait_irqs->timeout;

	ret = drmIoctl( fd,
		DRM_IOCTL_I915_PERFMON,
		&perfmon_ioctl);

	wait_irqs->ret_code = perfmon_ioctl.data.wait_irqs.ret_code;

	return ret;
}

int
drm_intel_perfmon_set_irq(int fd, unsigned int enable)
{

	struct drm_i915_perfmon perfmon_ioctl;
	int ret;

	perfmon_ioctl.op = I915_PERFMON_SET_BUFFER_IRQS;
	perfmon_ioctl.data.set_irqs.enable = enable;

	ret = drmIoctl( fd,
			DRM_IOCTL_I915_PERFMON,
			&perfmon_ioctl);

	return ret;
}

