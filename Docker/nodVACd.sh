#!/bin/sh
cd /opt/VACio/bin

if [ -f '/opt/VACio/bin/data-dir/config.ini' ]; then
    echo
  else
    cp /config.ini /opt/VACio/bin/data-dir
fi

if [ -d '/opt/VACio/bin/data-dir/contracts' ]; then
    echo
  else
    cp -r /contracts /opt/VACio/bin/data-dir
fi

while :; do
    case $1 in
        --config-dir=?*)
            CONFIG_DIR=${1#*=}
            ;;
        *)
            break
    esac
    shift
done

if [ ! "$CONFIG_DIR" ]; then
    CONFIG_DIR="--config-dir=/opt/VACio/bin/data-dir"
else
    CONFIG_DIR=""
fi

exec /opt/VACio/bin/nodVAC $CONFIG_DIR "$@"
