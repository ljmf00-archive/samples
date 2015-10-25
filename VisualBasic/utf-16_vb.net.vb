Imports System.Data.SqlClient
Imports System.IO
Imports System.Security.Cryptography

Public Class utf_16

    Private enc As System.Text.UTF8Encoding
    Private encryptor As ICryptoTransform
    Private decryptor As ICryptoTransform

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Console.WriteLine(System.DateTime.Now.ToString & "> " & "Encrypt")
        Dim sPlainText As String = Me.TextBox1.Text
        If Not String.IsNullOrEmpty(sPlainText) Then
            Dim memoryStream As MemoryStream = New MemoryStream()
            Dim cryptoStream As CryptoStream = New CryptoStream(memoryStream, Me.encryptor, CryptoStreamMode.Write)
            cryptoStream.Write(Me.enc.GetBytes(sPlainText), 0, sPlainText.Length)
            cryptoStream.FlushFinalBlock()
            Me.TextBox1.Text = Convert.ToBase64String(memoryStream.ToArray())
            memoryStream.Close()
            cryptoStream.Close()
        End If
        Console.WriteLine(System.DateTime.Now.ToString & "> " & "Encrypted")
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Console.WriteLine(System.DateTime.Now.ToString & "> " & "Decrypt")
        Dim cypherTextBytes As Byte() = Convert.FromBase64String(Me.TextBox1.Text)
        Dim memoryStream As MemoryStream = New MemoryStream(cypherTextBytes)
        Dim cryptoStream As CryptoStream = New CryptoStream(memoryStream, Me.decryptor, CryptoStreamMode.Read)
        Dim plainTextBytes(cypherTextBytes.Length) As Byte
        Dim decryptedByteCount As Integer = cryptoStream.Read(plainTextBytes, 0, plainTextBytes.Length)
        memoryStream.Close()
        cryptoStream.Close()
        Me.TextBox1.Text = Me.enc.GetString(plainTextBytes, 0, decryptedByteCount)
        Console.WriteLine(System.DateTime.Now.ToString & "> " & "Decrypted")
    End Sub

    Private Sub Form_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load
        Console.WriteLine(System.DateTime.Now.ToString & "> " & "UTF form load")
        Console.WriteLine(System.DateTime.Now.ToString & "> " & "Load UTF16 Encrypt Code")
        Dim KEY_128 As Byte() = {42, 1, 52, 67, 231, 13, 94, 101, 123, 6, 0, 12, 32, 91, 4, 111, 31, 70, 21, 141, 123, 142, 234, 82, 95, 129, 187, 162, 12, 55, 98, 23}
        Dim IV_128 As Byte() = {234, 12, 52, 44, 214, 222, 200, 109, 2, 98, 45, 76, 88, 53, 23, 78}
        Dim symmetricKey As RijndaelManaged = New RijndaelManaged()
        symmetricKey.Mode = CipherMode.CBC

        Me.enc = New System.Text.UTF8Encoding
        Me.encryptor = symmetricKey.CreateEncryptor(KEY_128, IV_128)
        Me.decryptor = symmetricKey.CreateDecryptor(KEY_128, IV_128)
        Console.WriteLine(System.DateTime.Now.ToString & "> " & "Loaded")
    End Sub
End Class