/* Copyright 2017 - 2023 R. Thomas
 * Copyright 2017 - 2023 Quarkslab
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef LIEF_PE_LOAD_CONFIGURATION_V11_H
#define LIEF_PE_LOAD_CONFIGURATION_V11_H
#include <ostream>

#include "LIEF/visibility.h"

#include "LIEF/PE/enums.hpp"
#include "LIEF/PE/LoadConfigurations/LoadConfigurationV10.hpp"

namespace LIEF {
namespace PE {

namespace details {
template<class T>
struct load_configuration_v11;
}

class LIEF_API LoadConfigurationV11 : public LoadConfigurationV10 {
  public:

  static constexpr WIN_VERSION VERSION = WIN_VERSION::WIN10_0_MSVC_2019_16;
  LoadConfigurationV11();

  template<class T>
  LIEF_LOCAL LoadConfigurationV11(const details::load_configuration_v11<T>& header);

  LoadConfigurationV11& operator=(const LoadConfigurationV11&);
  LoadConfigurationV11(const LoadConfigurationV11&);

  WIN_VERSION version() const override {
    return LoadConfigurationV11::VERSION;
  }

  uint64_t cast_guard_os_determined_failure_mode() const {
    return cast_guard_os_determined_failure_mode_;
  }

  void cast_guard_os_determined_failure_mode(uint64_t value) {
    cast_guard_os_determined_failure_mode_ = value;
  }

  static bool classof(const LoadConfiguration* config) {
    return config->version() == VERSION;
  }

  ~LoadConfigurationV11() override;

  void accept(Visitor& visitor) const override;

  bool operator==(const LoadConfigurationV11& rhs) const;
  bool operator!=(const LoadConfigurationV11& rhs) const;

  std::ostream& print(std::ostream& os) const override;

  protected:
  uint64_t cast_guard_os_determined_failure_mode_ = 0;
};
}
}

#endif
