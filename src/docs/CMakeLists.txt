# Copyright (c) 2019 Jürgen Mülbert. All rights reserved.
#
# This file is part of jmbde
#
# Licensed under the EUPL, Version 1.2 or – as soon they
# will be approved by the European Commission - subsequent
# versions of the EUPL (the "Licence");
# You may not use this work except in compliance with the
# Licence.
# You may obtain a copy of the Licence at:
#
# https://joinup.ec.europa.eu/page/eupl-text-11-12
#
# Unless required by applicable law or agreed to in
# writing, software distributed under the Licence is
# distributed on an "AS IS" basis,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
# express or implied.
# See the Licence for the specific language governing
# permissions and limitations under the Licence.
#
# Lizenziert unter der EUPL, Version 1.2 oder - sobald
#  diese von der Europäischen Kommission genehmigt wurden -
# Folgeversionen der EUPL ("Lizenz");
# Sie dürfen dieses Werk ausschließlich gemäß
# dieser Lizenz nutzen.
# Eine Kopie der Lizenz finden Sie hier:
#
# https://joinup.ec.europa.eu/page/eupl-text-11-12
#
# Sofern nicht durch anwendbare Rechtsvorschriften
# gefordert oder in schriftlicher Form vereinbart, wird
# die unter der Lizenz verbreitete Software "so wie sie
# ist", OHNE JEGLICHE GEWÄHRLEISTUNG ODER BEDINGUNGEN -
# ausdrücklich oder stillschweigend - verbreitet.
# Die sprachspezifischen Genehmigungen und Beschränkungen
# unter der Lizenz sind dem Lizenztext zu entnehmen.

# minimal requirements
cmake_minimum_required(VERSION 3.12.4 FATAL_ERROR)

find_package(Doxygen)
set_package_properties(Doxygen PROPERTIES
  TYPE OPTIONAL
  DESCRIPTION "API Documentation system"
  URL "http://www.doxygen.org"
  PURPOSE "Needed to build the API documentation."
)

find_package(Sphinx)
set_package_properties(Sphinx PROPERTIES
  TYPE OPTIONAL
  DESCRIPTION "Manual build system"
  URL "http://www.sphinx-doc.org"
  PURPOSE "Needed to build the manual."
)

if(SPHINX_EXECUTABLE AND BUILD_MANUAL)
  add_subdirectory(manual)
endif()

if(DOXYGEN_FOUND AND BUILD_API_DOCS)
  add_subdirectory(api)
endif()
