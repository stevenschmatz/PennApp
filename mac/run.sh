cd ../pebble-app
pebble build
pebble install --phone 158.130.164.180
pebble logs --phone 158.130.164.180 | node ../mac/run.js