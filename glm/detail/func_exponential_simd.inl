/// @ref core
/// @file glm/detail/func_exponential_simd.inl

#include "../simd/exponential.h"

#if GLM_ARCH & GLM_ARCH_SSE2_BIT

namespace glm{
namespace detail
{
	template <precision P>
	struct compute_sqrt<tvec4, float, P>
	{
		GLM_FUNC_QUALIFIER static tvec4<float, P> call(tvec4<float, P> const & v)
		{
			tvec4<float, P> result(uninitialize);
			result.data = _mm_sqrt_ps(v.data);
			return result;
		}
	};

	template <>
	struct compute_sqrt<tvec4, float, lowp>
	{
		GLM_FUNC_QUALIFIER static tvec4<float, lowp> call(tvec4<float, lowp> const & v)
		{
			tvec4<float, lowp> result(uninitialize);
			result.data = glm_f32v4_sqrt_lowp(v.data);
			return result;
		}
	};
}//namespace detail
}//namespace glm

#endif//GLM_ARCH & GLM_ARCH_SSE2_BIT