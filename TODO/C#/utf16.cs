using System;
using System.IO;
using System.Security.Cryptography;

namespace totalLibrary.Cryptography
{
    public class Utf16
    {
        public static System.Text.UTF8Encoding enc;
        public static ICryptoTransform encryptor;
        public static ICryptoTransform decryptor;
        public static string utf16_encrypt(string input)
        {
            string sPlainText = input;
            string output = "";
            if (!string.IsNullOrEmpty(sPlainText))
            {
                MemoryStream memoryStream = new MemoryStream();
                CryptoStream cryptoStream = new CryptoStream(memoryStream, encryptor, CryptoStreamMode.Write);
                cryptoStream.Write(enc.GetBytes(sPlainText), 0, sPlainText.Length);
                cryptoStream.FlushFinalBlock();
                output = Convert.ToBase64String(memoryStream.ToArray());
                memoryStream.Close();
                cryptoStream.Close();
            }
            return output;
        }
        public static string utf16_decrypt(string input)
        {
            string output = "";
            if (!string.IsNullOrEmpty(input))
            {
                byte[] cypherTextBytes = Convert.FromBase64String(input);
                MemoryStream memoryStream = new MemoryStream(cypherTextBytes);
                CryptoStream cryptoStream = new CryptoStream(memoryStream, decryptor, CryptoStreamMode.Read);
                byte[] plainTextBytes = new byte[cypherTextBytes.Length + 1];
                int decryptedByteCount = cryptoStream.Read(plainTextBytes, 0, plainTextBytes.Length);
                memoryStream.Close();
                cryptoStream.Close();
                output = enc.GetString(plainTextBytes, 0, decryptedByteCount);
            }

            return output;
        }

    }
}