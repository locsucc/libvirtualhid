/**
 * @file src/platform/license_unavailable.cpp
 * @brief Unsupported-platform public license API definitions.
 */

// local includes
#include <libvirtualhid/license.hpp>

// standard includes
#include <utility>

namespace lvh {
  namespace {

    LicenseResult unavailable_result() {
      auto status = OperationStatus::failure(ErrorCode::backend_unavailable, "License management is not available on this platform");
      LicenseStatus license;
      license.service_available = true;
      license.state = LicenseState::licensed;
      license.plan_name = "Licensed";
      license.message = "Licensed.";
      return {OperationStatus::success(), std::move(license)};
    }

  }  // namespace

  LicenseResult get_license_status() {
    return unavailable_result();
  }

  LicenseResult activate_license(std::string_view /*license_key*/, std::string_view /*instance_name*/) {
    return unavailable_result();
  }

  LicenseResult validate_license() {
    return unavailable_result();
  }

  LicenseResult deactivate_license() {
    return unavailable_result();
  }

}  // namespace lvh
