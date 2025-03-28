#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/outputs.h>
#include "keys_de.h"

#define APT 0
#define NUM 1
#define NAV 2
#define SYM 3
#define DE 4

// &lt {
//     quick_tap_ms = <170>;
// };

&caps_word {
    continue-list = <UNDERSCORE MINUS BSPC LSHFT RSHFT>;
};


/ {
    combos {
        compatible = "zmk,combos";
/* usually on base layer */
        combo_q {
            timeout-ms = <40>;
            key-positions = <1 2>;
            bindings = <&kp Q>;
            layers = <APT>;
        };
        combo_z {
            timeout-ms = <40>;
            key-positions = <18 19>;
            bindings = <&kp DE_Z>;
        };
        combo_v {
            timeout-ms = <40>;
            key-positions = <0 1>;
            bindings = <&kp V>;
            layers = <APT>;
        };
        combo_slash {
            timeout-ms = <40>;
            key-positions = <22 23>;
            bindings = <&kp SLASH>;
        };
        combo_minus {
            timeout-ms = <40>;
            key-positions = <21 22>;
            bindings = <&kp MINUS>;
        };
        combo_esc {
            timeout-ms = <40>;
            key-positions = <19 20>;
            bindings = <&kp ESC>;
        };
/* parentheticals */
        combo_lbrc {
            timeout-ms = <40>;
            key-positions = <0 9>;
            bindings = <&kp DE_LBRC>;
        };
        combo_lbkt {
            timeout-ms = <40>;
            key-positions = <1 10>;
            bindings = <&kp DE_LBKT>;
        };
        combo_lpar {
            timeout-ms = <40>;
            key-positions = <2 11>;
            bindings = <&kp DE_LPAR>;
        };
        combo_lt {
            timeout-ms = <40>;
            key-positions = <3 12>;
            bindings = <&kp DE_LT>;
        };
        combo_gt {
            timeout-ms = <40>;
            key-positions = <4 13>;
            bindings = <&kp DE_GT>;
        };
        combo_rpar {
            timeout-ms = <40>;
            key-positions = <5 14>;
            bindings = <&kp DE_RPAR>;
        };
        combo_rbkt {
            timeout-ms = <40>;
            key-positions = <6 15>;
            bindings = <&kp DE_RBKT>;
        };
        combo_rbrc {
            timeout-ms = <40>;
            key-positions = <7 16>;
            bindings = <&kp DE_RBRC>;
        };
/* caps */
        combo_caps-word {
            timeout-ms = <40>;
            key-positions = <11 14>;
            bindings = <&caps_word>;
        };
        combo_capslock {
            timeout-ms = <40>;
            key-positions = <0 7>;
            bindings = <&kp CAPSLOCK>;
        };
/* deletion */
        combo_bspc {
            timeout-ms = <40>;
            key-positions = <5 6>;
            bindings = <&kp BSPC>;
        };
        combo_del {
            timeout-ms = <40>;
            key-positions = <6 7>;
            bindings = <&kp DEL>;
        };
        combo_delword {
            timeout-ms = <40>;
            key-positions = <5 7>;
            bindings = <&kp LC(BSPC)>;
        };
/*F keys*/
        combo_F11 {
          timeout-ms = <40>;
          key-positions = <0 1>;
          layers = <NUM>;
          bindings = <&kp F11>;
        };
        combo_F12 {
          timeout-ms = <40>;
          key-positions = <1 2>;
          layers = <NUM>;
          bindings = <&kp F12>;
        };
    };
};


/ {

    behaviors {
        hl: homerow_mods_left {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods left";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <4 5 6 7 13 14 15 16 17 21 22 23 24 25 26 27>;
        };
        hr: homerow_mods_right {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods right";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <0 1 2 3 8 9 10 11 12 18 19 20 24 25 26 27>;
        };

        my_lt: my_layer_taps {
            compatible = "zmk,behavior-hold-tap";
            label = "my layer taps";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&mo &kp>, <&kp>;
            // non-thumb keys
            hold-trigger-key-positions = <0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27>;
        };

        dotcol: dot_colon {
            compatible = "zmk,behavior-mod-morph";
            label = "DOT_COL";
            #binding-cells = <0>;
            bindings = <&kp DOT>, <&kp COLON>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
        comsem: comma_semicolon {
            compatible = "zmk,behavior-mod-morph";
            label = "COM_SEM";
            #binding-cells = <0>;
            bindings = <&kp COMMA>, <&kp SEMI>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
    };
};
