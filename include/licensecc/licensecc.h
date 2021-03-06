/** \addtogroup api
 * @{
 */
#ifndef LICENSEPP_H_
#define LICENSEPP_H_

/*
 * This include file is the public api di Licensecc
 */
#ifdef __cplusplus
extern "C" {
#endif

#include <licensecc_properties.h>

#include "datatypes.h"

/**
 * Method used to convert the LicenseInfo into a human readable
 * representation.
 */
void print_error(char out_buffer[LCC_API_ERROR_BUFFER_SIZE], LicenseInfo* licenseInfo);

/**
 * \brief Calculates the hardware identifier associated with a specific pc.
 * \details
 * The software, when it doesn't find a valid license should show to the user the calculated identifier.
 * The user should report the pc_identifier to the software editor that will in turn use it to issue a license.
 *
 * pc_id_method = ::STRATEGY_DEFAULT is usually the best choice.
 *
 * First call this method with `identifier_out` = nullptr and `buf_size` = 0 , it will return the requested buffer size
 * in `buf_size` parameter.
 *
 * Then allocate the necessary memory, and call the method again.
 *
 * @return true if successful, false if failure (because it is not possible to identify or buffer too small).
 * @param hw_id_method[in] specifies a preferred identification method. Usually #STRATEGY_DEFAULT works well. See the
 * wiki for more informations.
 * @param identifier_out[out] buffer where the identification string will be placed.
 * @param identifier_out[in-out] size of the buffer where the identification string will be placed.
 */
bool identify_pc(LCC_API_HW_IDENTIFICATION_STRATEGY hw_id_method, char* identifier_out, size_t* buf_size);

/**
 * This method is used to request the use of one license for a product.
 * In case of local license it's used to check if the product is licensed.
 *
 * @return ::LICENSE_OK(0) if successful. Other values if there are errors.
 * 
 * @param callerInformation[in]
 * 			a vendor defined string containing the name of the product we want to request.
 * @param licenseLocation[in] otpional, can be NULL.
 * 					licenseLocation, either the name of the file
 * 								or the name of the environment variable should be !='\0'
 * @param license_out[out] optional, can be NULL, if set it will return extra informations about the license.
 */

LCC_EVENT_TYPE acquire_license(const CallerInformations* callerInformation, const LicenseLocation* licenseLocation,
						   LicenseInfo* license_out);

/**
 * Not implemented yet, useful (later) for network licenses.
 * Should be called from time to time to confirm we're still using the
 * license.
 */
LCC_EVENT_TYPE confirm_license(char* featureName, LicenseLocation* licenseLocation);
/**
 * Not implemented yet, useful (later) for network licenses.
 */
LCC_EVENT_TYPE release_license(char* featureName, LicenseLocation licenseLocation);

#ifdef __cplusplus
}
#endif

#endif
/**
 * @}
 */
