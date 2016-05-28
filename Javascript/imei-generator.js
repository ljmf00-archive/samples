function imei_gen() {
    var pos;
    var str = new Array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    var sum = 0;
    var final_digit = 0;
    var t = 0;
    var len_offset = 0;
    var len = 15;
    var issuer;
    var rbi = ["01","10","30","33","35","44","45","49","50","51","52","53","54","86","91","98","99"];
    var arr = rbi[Math.floor(Math.random() * rbi.length)].split("");
    str[0] = Number(arr[0]);
    str[1] = Number(arr[1]);
    pos = 2;
    while (pos < len - 1) {
        str[pos++] = Math.floor(Math.random() * 10) % 10;
    }
    len_offset = (len + 1) % 2;
    for (pos = 0; pos < len - 1; pos++) {
        if ((pos + len_offset) % 2) {
            t = str[pos] * 2;
            if (t > 9) {
                t -= 9;
            }
            sum += t;
        }
        else {
            sum += str[pos];
        }
    }
    final_digit = (10 - (sum % 10)) % 10;
    str[len - 1] = final_digit;
    t = str.join('');
    t = t.substr(0, len);
    document.getElementById('imei_num').value = t;
}