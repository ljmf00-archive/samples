using Microsoft.VisualBasic;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Data;
using System.Diagnostics;
using System.Data.SqlClient;
using System.IO;
using System.Security.Cryptography;

public class utf_16
{

	private System.Text.UTF8Encoding enc;
	private ICryptoTransform encryptor;

	private ICryptoTransform decryptor;
	private void Button1_Click(System.Object sender, System.EventArgs e)
	{
		Console.WriteLine(System.DateTime.Now.ToString + "> " + "Encrypt");
		string sPlainText = this.TextBox1.Text;
		if (!string.IsNullOrEmpty(sPlainText)) {
			MemoryStream memoryStream = new MemoryStream();
			CryptoStream cryptoStream = new CryptoStream(memoryStream, this.encryptor, CryptoStreamMode.Write);
			cryptoStream.Write(this.enc.GetBytes(sPlainText), 0, sPlainText.Length);
			cryptoStream.FlushFinalBlock();
			this.TextBox1.Text = Convert.ToBase64String(memoryStream.ToArray());
			memoryStream.Close();
			cryptoStream.Close();
		}
		Console.WriteLine(System.DateTime.Now.ToString + "> " + "Encrypted");
	}

	private void Button2_Click(System.Object sender, System.EventArgs e)
	{
		Console.WriteLine(System.DateTime.Now.ToString + "> " + "Decrypt");
		byte[] cypherTextBytes = Convert.FromBase64String(this.TextBox1.Text);
		MemoryStream memoryStream = new MemoryStream(cypherTextBytes);
		CryptoStream cryptoStream = new CryptoStream(memoryStream, this.decryptor, CryptoStreamMode.Read);
		byte[] plainTextBytes = new byte[cypherTextBytes.Length + 1];
		int decryptedByteCount = cryptoStream.Read(plainTextBytes, 0, plainTextBytes.Length);
		memoryStream.Close();
		cryptoStream.Close();
		this.TextBox1.Text = this.enc.GetString(plainTextBytes, 0, decryptedByteCount);
		Console.WriteLine(System.DateTime.Now.ToString + "> " + "Decrypted");
	}

	private void Form_Load(object sender, System.EventArgs e)
	{
		Console.WriteLine(System.DateTime.Now.ToString + "> " + "UTF form load");
		Console.WriteLine(System.DateTime.Now.ToString + "> " + "Load UTF16 Encrypt Code");
		byte[] KEY_128 = {
			42,
			1,
			52,
			67,
			231,
			13,
			94,
			101,
			123,
			6,
			0,
			12,
			32,
			91,
			4,
			111,
			31,
			70,
			21,
			141,
			123,
			142,
			234,
			82,
			95,
			129,
			187,
			162,
			12,
			55,
			98,
			23
		};
		byte[] IV_128 = {
			234,
			12,
			52,
			44,
			214,
			222,
			200,
			109,
			2,
			98,
			45,
			76,
			88,
			53,
			23,
			78
		};
		RijndaelManaged symmetricKey = new RijndaelManaged();
		symmetricKey.Mode = CipherMode.CBC;

		this.enc = new System.Text.UTF8Encoding();
		this.encryptor = symmetricKey.CreateEncryptor(KEY_128, IV_128);
		this.decryptor = symmetricKey.CreateDecryptor(KEY_128, IV_128);
		Console.WriteLine(System.DateTime.Now.ToString + "> " + "Loaded");
	}
	public utf_16()
	{
		Load += Form_Load;
	}
}