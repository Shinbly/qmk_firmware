diff --git a/keyboards/nullbitsco/snap/config.h b/keyboards/nullbitsco/snap/config.h
index 9559a34352..f84a3f3c9b 100644
--- a/keyboards/nullbitsco/snap/config.h
+++ b/keyboards/nullbitsco/snap/config.h
@@ -4,6 +4,10 @@
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
+
+#ifdef CONVERT_TO_RP2040_CE
+    #include "mcus/rp2040_config.h"
+#endif
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
diff --git a/keyboards/nullbitsco/snap/keyboard.json b/keyboards/nullbitsco/snap/keyboard.json
index 139bbf5b45..e3442098ce 100644
--- a/keyboards/nullbitsco/snap/keyboard.json
+++ b/keyboards/nullbitsco/snap/keyboard.json
@@ -61,8 +61,8 @@
         "pin": "B2"
     },
     "debounce": 10,
-    "processor": "atmega32u4",
-    "bootloader": "atmel-dfu",
+        "processor": "RP2040",
+    "bootloader": "rp2040",
     "layouts": {
         "LAYOUT_all": {
             "layout": [
diff --git a/keyboards/nullbitsco/snap/rules.mk b/keyboards/nullbitsco/snap/rules.mk
index 1603cb408c..dab37880e0 100644
--- a/keyboards/nullbitsco/snap/rules.mk
+++ b/keyboards/nullbitsco/snap/rules.mk
@@ -2,6 +2,11 @@ CUSTOM_MATRIX = lite
 
 UART_DRIVER_REQUIRED = yes
 
+# Include RP2040 specific rules if we're converting
+ifdef CONVERT_TO_RP2040_CE
+    include mcus/rp2040_rules.mk
+endif
+
 # Project specific files
 SRC +=  common/bitc_led.c \
         common/remote_kb.c \
