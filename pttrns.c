
TWO_0 = 11
TWO_1 = 101
TWO_2 = 1001

THR_0 = 111
THR_1 = 1011
THR_2 = 10011
THR_3 = 10101

FOR_0 = 1111
FOR_1 = 10111
FOR_2 = 11011

FIVER = 11111



case 00001: m[s+1] = TWO_0; m[s+2] = TWO_1; m[s+3] = TWO_2; break;
case 00010: m[s+0] = TWO_0; m[s+3] = TWO_1; m[s+4] = TWO_2; break; 
case 00011: m[s+2] = THR_0; m[s+2] = THR_1; m[s+3] = THR_2; break;

case 00100: m[s+0] = TWO_1; m[s+1] = TWO_0; m[s+3] = TWO_0; m[s+4] = TWO_1; break;
case 00101: m[s+1] = THR_0; m[s+3] = THR_1; m[s+4] = THR_3; break;
case 00110: m[s+0] = THR_0; m[s+3] = THR_0; m[s+4] = THR_1; break;
case 00111: m[s+3] = FOR_0; m[s+4] = FOR_1; break;

case 01000: m[s+0] = TWO_2; m[s+1] = TWO_1; m[s+2] = TWO_0; m[s+4] = TWO_0; break;
case 01001: m[s+1] = THR_1; m[s+2] = THR_1; m[s+4] = THR_2; break;

case 01010: m[s+0] = THR_1; m[s+2] = THR_0; m[s+4] = THR_1; break;
case 01011: m[s+2] = FOR_0; m[s+4] = FOR_2; break;
case 01100: m[s+0] = THR_1; m[s+1] = THR_0; m[s+4] = THR_0; break;
case 01101: m[s+1] = FOR_0; m[s+4] = FOR_1; break;

case 01110: m[s+0] = FOR_0; m[s+4] = FOR_0; break;

case 01111: m[s+4] = FIVER; break;
case 10000: m[s+1] = TWO_2; m[s+2] = TWO_1; m[s+3] = TWO_0; break;
case 10001: m[s+1] = THR_2; m[s+2] = THR_3; m[s+3] = THR_2; break;

case 10010: m[s+0] = THR_2; m[s+2] = THR_1; m[s+3] = THR_1; break;
case 10011: m[s+2] = FOR_1; m[s+3] = FOR_2; break;
case 10100: m[s+0] = THR_3; m[s+1] = THR_1; m[s+3] = THR_0; break;

case 10101: m[s+1] = FOR_1; m[s+3] = FOR_1; break;
case 10110: m[s+0] = FOR_1; m[s+3] = FOR_0; break;
case 10111: m[s+3] = FIVER; break;

case 11000: m[s+0] = THR_3; m[s+1] = THR_1; m[s+2] = THR_0; break;
case 11001: m[s+1] = FOR_2; m[s+2] = FOR_1; break;
case 11010: m[s+0] = FOR_2; m[s+1] = FOR_0; break;
case 11011: m[s+2] = FIVER; break;
case 11100: m[s+0] = FOR_1; m[s+1] = FOR_0; break;
case 11101: m[s+1] = FIVER; break;
case 11110: m[s+0] = FIVER; break;