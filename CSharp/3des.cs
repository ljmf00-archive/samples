using System.Security.Cryptography;
using System;
using System.Text;


namespace totalLibrary.Cryptography
{
    public class _3DES
    {
        public static string _3des_encrypt(string phrase, string key, bool hashKey = true)
        {
            var keyArray = HexStringToByteArray(hashKey ? totalLibrary.Cryptography.Md5.HashMD5(key) : key);
            var toEncryptArray = Encoding.UTF8.GetBytes(phrase);

            var tdes = new TripleDESCryptoServiceProvider
            {
                Key = keyArray,
                Mode = CipherMode.ECB,
                Padding = PaddingMode.PKCS7
            };

            var cTransform = tdes.CreateEncryptor();
            var resultArray = cTransform.TransformFinalBlock(toEncryptArray, 0, toEncryptArray.Length);

            tdes.Clear();
            return ByteArrayToHexString(resultArray);
        }
        public static string _3des_decrypt(string hash, string key, bool hashKey = true)
        {
            var keyArray = HexStringToByteArray(hashKey ? totalLibrary.Cryptography.Md5.HashMD5(key) : key);
            var toEncryptArray = HexStringToByteArray(hash);

            var tdes = new TripleDESCryptoServiceProvider
            {
                Key = keyArray,
                Mode = CipherMode.ECB,
                Padding = PaddingMode.PKCS7
            };

            var cTransform = tdes.CreateDecryptor();
            var resultArray = cTransform.TransformFinalBlock(toEncryptArray, 0, toEncryptArray.Length);

            tdes.Clear();
            return Encoding.UTF8.GetString(resultArray);
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
