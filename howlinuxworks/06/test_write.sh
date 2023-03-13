#!/bin/bash
echo "$(date): without page cache"
dd if=/dev/zero of=testfile oflag=direct bs=1M count=1K
echo "$(date): write finished"
rm -f testfile

echo "$(date): with page cache"
dd if=/dev/zero of=testfile bs=1M count=1K
echo "$(date): write finished"
rm -f testfile