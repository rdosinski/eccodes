#!/bin/sh
# (C) Copyright 2005- ECMWF.
#
# This software is licensed under the terms of the Apache Licence Version 2.0
# which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
# 
# In applying this licence, ECMWF does not waive the privileges and immunities granted to it by
# virtue of its status as an intergovernmental organisation nor does it submit to any jurisdiction.
#

. ./include.ctest.sh

label="codes_compare_keys_test"
tempRef=temp.${label}.ref
tempLog=temp.$label.log

file1=$ECCODES_SAMPLES_PATH/reduced_gg_pl_32_grib2.tmpl
file2=$ECCODES_SAMPLES_PATH/reduced_gg_pl_48_grib2.tmpl
set +e
$EXEC ${test_dir}/codes_compare_keys $file1 $file2 > $tempLog 2>&1
status=$?
set -e
[ $status -ne 0 ]

cat > $tempRef <<EOF
key: totalLength  (Long values are different)
key: section3Length  (Long values are different)
key: numberOfDataPoints  (Long values are different)
key: Nj  (Long values are different)
key: latitudeOfFirstGridPoint  (Long values are different)
key: latitudeOfLastGridPoint  (Long values are different)
key: longitudeOfLastGridPoint  (Long values are different)
key: N  (Long values are different)
key: pl  (Count mismatch)
key: hoursAfterDataCutoff  (Long values are different)
key: minutesAfterDataCutoff  (Long values are different)
key: numberOfValues  (Long values are different)
key: referenceValue  (Double values are different)

Comparison failed: One or more keys are different
EOF

diff $tempRef $tempLog

rm -f $tempLog $tempRef
