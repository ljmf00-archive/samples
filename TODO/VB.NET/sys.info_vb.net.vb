Imports System.Management
Imports System.Environment
Imports System.Text

Public Class systeminfo
    Private Function SystemInformation() As String
        Dim StringBuilder1 As New StringBuilder(String.Empty)
        Try
            StringBuilder1.AppendFormat("Operation System:  {0}" & vbLf, Environment.OSVersion)
            If Environment.Is64BitOperatingSystem Then
                StringBuilder1.AppendFormat(vbTab & vbTab & "  64 Bit Operating System" & vbLf)
            Else
                StringBuilder1.AppendFormat(vbTab & vbTab & "  32 Bit Operating System" & vbLf)
            End If
            StringBuilder1.AppendFormat("SystemDirectory:  {0}" & vbLf, Environment.SystemDirectory)
            StringBuilder1.AppendFormat("ProcessorCount:  {0}" & vbLf, Environment.ProcessorCount)
            StringBuilder1.AppendFormat("UserDomainName:  {0}" & vbLf, Environment.UserDomainName)
            StringBuilder1.AppendFormat("UserName: {0}" & vbLf, Environment.UserName)
            'Drives
            StringBuilder1.AppendFormat("LogicalDrives:" & vbLf)
            For Each DriveInfo1 As System.IO.DriveInfo In System.IO.DriveInfo.GetDrives()
                Try
                    StringBuilder1.AppendFormat(vbTab & " Drive: {0}" & vbLf & vbTab & vbTab & " VolumeLabel: " + "{1}" & vbLf & vbTab & vbTab & " DriveType: {2}" & vbLf & vbTab & vbTab & " DriveFormat: {3}" & vbLf & vbTab & vbTab & " " + "TotalSize: {4}" & vbLf & vbTab & vbTab & " AvailableFreeSpace: {5}" & vbLf, DriveInfo1.Name, DriveInfo1.VolumeLabel, DriveInfo1.DriveType, DriveInfo1.DriveFormat, DriveInfo1.TotalSize, _
                        DriveInfo1.AvailableFreeSpace)
                Catch
                End Try
            Next
            StringBuilder1.AppendFormat("SystemPageSize:  {0}" & vbLf, Environment.SystemPageSize)
            StringBuilder1.AppendFormat("Version:  {0}", Environment.Version)
        Catch
        End Try
        Return StringBuilder1.ToString()
    End Function

    Private Function DeviceInformation(stringIn As String) As String
        Dim StringBuilder1 As New StringBuilder(String.Empty)
        Dim ManagementClass1 As New ManagementClass(stringIn)
        'Create a ManagementObjectCollection to loop through
        Dim ManagemenobjCol As ManagementObjectCollection = ManagementClass1.GetInstances()
        'Get the properties in the class
        Dim properties As PropertyDataCollection = ManagementClass1.Properties
        For Each obj As ManagementObject In ManagemenobjCol
            For Each [property] As PropertyData In properties
                Try
                    StringBuilder1.AppendLine([property].Name + ":  " + obj.Properties([property].Name).Value.ToString())
                    'Add codes to manage more informations
                Catch
                End Try
            Next
            StringBuilder1.AppendLine()
        Next
        Return StringBuilder1.ToString()
    End Function
    Private Sub systeminfo_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        'System Information
        RichTextBox1.Text = SystemInformation()
        'CPU Information
        RichTextBox2.Text = DeviceInformation("Win32_Processor")
        'Local Drives Information
        RichTextBox4.Text = DeviceInformation("Win32_LogicalDisk")
        'Video Controller Information
        RichTextBox3.Text = DeviceInformation("Win32_VideoController")
    End Sub
End Class