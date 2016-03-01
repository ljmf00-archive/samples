Imports System.Windows
Imports Microsoft.Office.Interop.Word
Imports System.Windows.Forms

Public Class doc2pdf

    Private Sub doc2pdf_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Console.WriteLine(System.DateTime.Now.ToString & "> " & "Open DOC2PDF converter")
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Console.WriteLine(System.DateTime.Now.ToString & "> " & "Open File Dialog")
        Dim dlg As New OpenFileDialog()

        ' Set filter for file extension and default file extension
        dlg.DefaultExt = ".doc"
        dlg.Filter = "Word documents (.doc)|*.docx;*.doc"

        ' Display OpenFileDialog by calling ShowDialog method
        Dim result As Nullable(Of Boolean) = dlg.ShowDialog()

        ' Get the selected file name and display in a TextBox
        If result = True Then
            ' Open document
            Dim filename As String = dlg.FileName
            TextBox1.Text = filename
        End If
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Console.WriteLine(System.DateTime.Now.ToString & "> " & "Converting")
        Dim appWord As New Microsoft.Office.Interop.Word.Application()
        wordDocument = appWord.Documents.Open(TextBox1.Text)
        Console.WriteLine(System.DateTime.Now.ToString & "> " & "Open Save dialog")
        Dim sfd As New SaveFileDialog()
        sfd.Filter = "PDF Documents|*.pdf"
        Try
            If sfd.ShowDialog() = System.Windows.Forms.DialogResult.OK Then
                Dim ext As String = System.IO.Path.GetExtension(sfd.FileName)
                Select Case ext
                    Case ".pdf"
                        wordDocument.ExportAsFixedFormat(sfd.FileName, WdExportFormat.wdExportFormatPDF)
                        TextBox2.Text = sfd.FileName
                        Exit Select
                        'case ".docx":
                        '    wordDocument.ExportAsFixedFormat(sfd.FileName, WdExportFormat.wdExportFormatPDF);
                        '    break;
                End Select
            End If
            Console.WriteLine(System.DateTime.Now.ToString & "> " & "Converted")
            System.Windows.Forms.MessageBox.Show("File Converted Successfully..")
        Catch ex As Exception
            System.Windows.Forms.MessageBox.Show(ex.Message)
        End Try
        Console.WriteLine(System.DateTime.Now.ToString & "> " & "Open file with Precces.Start")
        System.Diagnostics.Process.Start(sfd.FileName)
    End Sub
    Public Property wordDocument() As Microsoft.Office.Interop.Word.Document
        Get
            Return m_wordDocument
        End Get
        Set(value As Microsoft.Office.Interop.Word.Document)
            m_wordDocument = value
        End Set
    End Property
    Private m_wordDocument As Microsoft.Office.Interop.Word.Document
End Class