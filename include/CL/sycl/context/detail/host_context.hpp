#ifndef TRISYCL_SYCL_CONTEXT_DETAIL_HOST_CONTEXT_HPP
#define TRISYCL_SYCL_CONTEXT_DETAIL_HOST_CONTEXT_HPP

/** \file The OpenCL SYCL host context implementation

    Anastasi at Xilinx dot com

    This file is distributed under the University of Illinois Open Source
    License. See LICENSE.TXT for details.
*/

#include "CL/sycl/detail/default_classes.hpp"
#include "CL/sycl/detail/unimplemented.hpp"
#include "CL/sycl/detail/singleton.hpp"
#include "CL/sycl/exception.hpp"
#include "CL/sycl/info/param_traits.hpp"
#include "CL/sycl/info/platform.hpp"
#include "CL/sycl/context/detail/context.hpp"

namespace cl {
namespace sycl {
namespace detail {


/** \addtogroup execution Platforms, contexts, devices and queues
    @{

    SYCL host context

    \todo The implementation is quite minimal for now. :-)
*/
class host_context : public detail::context,
                     public detail::singleton<host_context> {

public:

#ifdef TRISYCL_OPENCL
  /** Return the underlying cl_context of the cl::sycl::context

      This throws an error since there is no OpenCL context associated
      to the host device.
  */
  cl_context get() const override {
    throw non_cl_error("The host context has no OpenCL context");
  }


  /** Return the SYCL platform that the context is initialized for

      This throws an error since there is no boost::compute context associated
      to the host device.
  */
  boost::compute::context &get_boost_compute() override {
    throw non_cl_error("The host context has no boost context");
  }


  /** Return the queue that is associated to the context

      This throws an error since there is no boost::command_queue context
      associated to the host device.
  */
  boost::compute::command_queue &get_boost_queue() override {
    throw non_cl_error("The host context has no boost queue");
  }
#endif


  /// Return true since the context is a SYCL host context
  bool is_host() const override {
    return true;
  }


  /** Return the platform of the context

      Return synchronous errors via the SYCL exception class.

      \todo To be implemented
  */
  cl::sycl::platform get_platform() const override {
    detail::unimplemented();
    return {};
  }

#if 0
  /** Query the context for OpenCL info::context info

      Return synchronous errors via the SYCL exception class.

      \todo To be implemented
  */
  template <info::context Param>
  typename info::param_traits<info::context, Param>::type
  get_info() const override {
    detail::unimplemented();
    return {};
  }
#endif

  /** Returns the set of devices that are part of this context.
      It should only return the host device itself.

      \todo To be implemented
  */
  vector_class<cl::sycl::device>
  get_devices() const override {
    detail::unimplemented();
    return {};
  }
};

/// @} to end the execution Doxygen group

}
}
}
#endif // TRISYCL_SYCL_CONTEXT_DETAIL_HOST_CONTEXT_HPP
