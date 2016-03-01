using System;
using System.Security.Cryptography;
using System.Text;

namespace totalLibrary.Cryptography
{
    public class SHA
    {
        public static string HashSHA1(string phrase)
        {
            if (phrase == null)
                return null;
            var encoder = new UTF8Encoding();
            var sha1Hasher = new SHA1CryptoServiceProvider();
            var hashedDataBytes = sha1Hasher.ComputeHash(encoder.GetBytes(phrase));
            return ByteArrayToHexString(hashedDataBytes);
        }
        public static string HashSHA256(string phrase)
        {
            if (phrase == null)
                return null;
            var encoder = new UTF8Encoding();
            var sha256Hasher = new SHA256CryptoServiceProvider();
            var hashedDataBytes = sha256Hasher.ComputeHash(encoder.GetBytes(phrase));
            return ByteArrayToHexString(hashedDataBytes);
        }
        public static string HashSHA384(string phrase)
        {
            if (phrase == null)
                return null;
            var encoder = new UTF8Encoding();
            var sha384Hasher = new SHA384CryptoServiceProvider();
            var hashedDataBytes = sha384Hasher.ComputeHash(encoder.GetBytes(phrase));
            return ByteArrayToHexString(hashedDataBytes);
        }
        public static string HashSHA512(string phrase)
        {
            if (phrase == null)
                return null;
            var encoder = new UTF8Encoding();
            var sha512Hasher = new SHA512CryptoServiceProvider();
            var hashedDataBytes = sha512Hasher.ComputeHash(encoder.GetBytes(phrase));
            return ByteArrayToHexString(hashedDataBytes);
        }
        internal static string ByteArrayToHexString(byte[] inputArray)
        {
            if (inputArray == null)
                return null;
            var o = new StringBuilder("");
            for (var i = 0; i < inputArray.Length; i++)
                o.Append(inputArray[i].ToString("X2"));
            return o.ToString();
        }
        internal static byte[] HexStringToByteArray(string inputString)
        {
            if (inputString == null)
                return null;

            if (inputString.Length == 0)
                return new byte[0];

            if (inputString.Length % 2 != 0)
                throw new Exception("Hex strings have an even number of characters and you have got an odd number of characters!");

            var num = inputString.Length / 2;
            var bytes = new byte[num];
            for (var i = 0; i < num; i++)
            {
                var x = inputString.Substring(i * 2, 2);
                try
                {
                    bytes[i] = Convert.ToByte(x, 16);
                }
                catch (Exception ex)
                {
                    throw new Exception("Part of your \"hex\" string contains a non-hex value.", ex);
                }
            }
            return bytes;
        }

    }
}
