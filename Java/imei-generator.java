package imei;


import java.util.concurrent.atomic.AtomicLong;

/**
 * http://en.wikipedia.org/wiki/International_Mobile_Station_Equipment_Identity
 */
public class IMEIGenerator {
    private static final int IMEI_LENGTH = 15;

    public static long next(long imei) {
        imei += 10;

        // the last imei is check number, so cut it off.
        imei /= 10;
        int check = checksum(imei);

        return imei * 10 + check;
    }

    public static int checksum(long imei) {

        int[] sum = new int[IMEI_LENGTH];
        long mod = 10;
        for (int i = 1; i <= 14; i++) {
            sum[i] = (int) (imei % mod);
            if (i % 2 != 0) {
                sum[i] *= 2;
            }
            if(sum[i] >= 10) {
                sum[i] = sum[i] % 10 + (sum[i] / 10);
            }
            imei /= mod;
        }

        int check = 0;
        for (int i = 0; i < sum.length; i++) {
            check += sum[i];
        }
        return (check * 9) % 10;
    }

    public static void main(String[] args) {
        int check = checksum(35806501910426L);
        System.err.println(check);
        assert check == 5;

        long next = next(358065019104265L);
        System.err.println(next);
    }
}