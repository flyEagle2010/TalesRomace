<GameProjectFile>
  <PropertyGroup Type="Scene" Name="LoginScene" ID="c9c4ebad-f9ca-467f-9cf0-6b37757d5487" Version="2.0.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1" />
      <ObjectData Name="Scene" CanEdit="False" FrameEvent="" ctype="SingleNodeObjectData">
        <Position X="0" Y="0" />
        <Scale ScaleX="1" ScaleY="1" />
        <AnchorPoint />
        <CColor A="255" R="255" G="255" B="255" />
        <Size X="1136" Y="640" />
        <PrePosition X="0" Y="0" />
        <PreSize X="0" Y="0" />
        <Children>
          <NodeObjectData Name="bg" ActionTag="40" FrameEvent="" Tag="25" ObjectIndex="2" ctype="SpriteObjectData">
            <Position X="568" Y="320" />
            <Scale ScaleX="1" ScaleY="1" />
            <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
            <CColor A="255" R="255" G="255" B="255" />
            <Size X="1136" Y="640" />
            <PrePosition X="0.5" Y="0.5" />
            <PreSize X="0" Y="0" />
            <FileData Type="PlistSubImage" Path="background.png" Plist="login.plist" />
          </NodeObjectData>
          <NodeObjectData Name="serverPage" ActionTag="41" Visible="False" FrameEvent="" Tag="26" ObjectIndex="1" TouchEnable="True" BackColorAlpha="102" ComboBoxIndex="1" ColorAngle="90" ctype="PanelObjectData">
            <Position X="0" Y="0" />
            <Scale ScaleX="1" ScaleY="1" />
            <AnchorPoint />
            <CColor A="255" R="255" G="255" B="255" />
            <Size X="1136" Y="640" />
            <PrePosition X="0" Y="0" />
            <PreSize X="1" Y="1" />
            <Children>
              <NodeObjectData Name="serverBg" ActionTag="39" FrameEvent="" Tag="24" ObjectIndex="1" ctype="SpriteObjectData">
                <Position X="568" Y="320" />
                <Scale ScaleX="1" ScaleY="1" />
                <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="835" Y="533" />
                <PrePosition X="0.5" Y="0.5" />
                <PreSize X="0" Y="0" />
                <FileData Type="PlistSubImage" Path="login_account login_plank_1.png" Plist="login.plist" />
              </NodeObjectData>
              <NodeObjectData Name="serverList" ActionTag="48" FrameEvent="" Tag="33" ObjectIndex="1" TouchEnable="True" BackColorAlpha="102" ComboBoxIndex="1" ColorAngle="90" ScrollDirectionType="Vertical" ctype="ScrollViewObjectData">
                <Position X="182.5" Y="86" />
                <Scale ScaleX="1" ScaleY="1" />
                <AnchorPoint />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="230" Y="400" />
                <PrePosition X="0.1606514" Y="0.134375" />
                <PreSize X="0.2024648" Y="0.625" />
                <Children>
                  <NodeObjectData Name="btn_serverGroup" ActionTag="56" FrameEvent="" Tag="41" ObjectIndex="2" TouchEnable="True" FontSize="14" ButtonText="" Scale9Width="188" Scale9Height="50" ctype="ButtonObjectData">
                    <Position X="118" Y="414" />
                    <Scale ScaleX="1" ScaleY="1" />
                    <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <Size X="188" Y="50" />
                    <PrePosition X="0.5130435" Y="0.92" />
                    <PreSize X="0" Y="0" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Default" Path="Default/Button_Disable.png" />
                    <PressedFileData Type="PlistSubImage" Path="login_account login_plank_3.png" Plist="login.plist" />
                    <NormalFileData Type="PlistSubImage" Path="login_account login_plank_2.png" Plist="login.plist" />
                  </NodeObjectData>
                </Children>
                <SingleColor A="255" R="255" G="150" B="100" />
                <FirstColor A="255" R="255" G="150" B="100" />
                <EndColor A="255" R="255" G="255" B="255" />
                <ColorVector ScaleY="1" />
                <InnerNodeSize Width="230" Height="450" />
              </NodeObjectData>
              <NodeObjectData Name="btn_server" ActionTag="57" FrameEvent="" Tag="42" ObjectIndex="3" TouchEnable="True" FontSize="14" ButtonText="" Scale9Width="227" Scale9Height="58" ctype="ButtonObjectData">
                <Position X="600" Y="426" />
                <Scale ScaleX="1" ScaleY="1" />
                <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="227" Y="58" />
                <PrePosition X="0.528169" Y="0.665625" />
                <PreSize X="0" Y="0" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" />
                <PressedFileData Type="PlistSubImage" Path="login_account login_plank_7.png" Plist="login.plist" />
                <NormalFileData Type="PlistSubImage" Path="login_account login_plank_4.png" Plist="login.plist" />
              </NodeObjectData>
              <NodeObjectData Name="lastServerTxt" ActionTag="59" FrameEvent="" Tag="44" ObjectIndex="1" FontSize="24" LabelText="内网。。。。" IsCustomSize="True" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ctype="TextObjectData">
                <Position X="750.5" Y="507" />
                <Scale ScaleX="1" ScaleY="1" />
                <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="200" Y="28" />
                <PrePosition X="0.6606514" Y="0.7921875" />
                <PreSize X="0.1760563" Y="0.04375" />
              </NodeObjectData>
            </Children>
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1" />
          </NodeObjectData>
          <NodeObjectData Name="countPage" ActionTag="42" FrameEvent="" Tag="27" ObjectIndex="2" TouchEnable="True" BackColorAlpha="102" ComboBoxIndex="1" ColorAngle="90" ctype="PanelObjectData">
            <Position X="0" Y="0" />
            <Scale ScaleX="1" ScaleY="1" />
            <AnchorPoint />
            <CColor A="255" R="255" G="255" B="255" />
            <Size X="1136" Y="640" />
            <PrePosition X="0" Y="0" />
            <PreSize X="0" Y="0" />
            <Children>
              <NodeObjectData Name="accountBg" ActionTag="43" FrameEvent="" Tag="28" ObjectIndex="3" ctype="SpriteObjectData">
                <Position X="568" Y="320" />
                <Scale ScaleX="1" ScaleY="1" />
                <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="565" Y="472" />
                <PrePosition X="0" Y="0" />
                <PreSize X="0" Y="0" />
                <FileData Type="PlistSubImage" Path="login_account login_3.png" Plist="login.plist" />
              </NodeObjectData>
              <NodeObjectData Name="btn_login" ActionTag="44" FrameEvent="" Tag="29" ObjectIndex="1" TouchEnable="True" FontSize="14" ButtonText="" Scale9Width="174" Scale9Height="70" ctype="ButtonObjectData">
                <Position X="568" Y="135" />
                <Scale ScaleX="1" ScaleY="1" />
                <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="174" Y="70" />
                <PrePosition X="0.5" Y="0.2109375" />
                <PreSize X="0" Y="0" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" />
                <PressedFileData Type="PlistSubImage" Path="login_in_2.png" Plist="login.plist" />
                <NormalFileData Type="PlistSubImage" Path="login_in_1.png" Plist="login.plist" />
              </NodeObjectData>
              <NodeObjectData Name="accountTxt" ActionTag="45" FrameEvent="" Tag="30" ObjectIndex="1" TouchEnable="True" FontSize="36" IsCustomSize="True" LabelText="" PlaceHolderText="输入账号" MaxLengthText="10" ctype="TextFieldObjectData">
                <Position X="622.5" Y="338" />
                <Scale ScaleX="1" ScaleY="1" />
                <AnchorPoint ScaleX="0.4979533" ScaleY="0.5" />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="350" Y="60" />
                <PrePosition X="0.5479754" Y="0.528125" />
                <PreSize X="0.3080986" Y="0.09375" />
              </NodeObjectData>
              <NodeObjectData Name="passTxt" ActionTag="46" FrameEvent="" Tag="31" ObjectIndex="2" TouchEnable="True" FontSize="36" IsCustomSize="True" LabelText="" PlaceHolderText="输入密码" MaxLengthText="10" PasswordEnable="True" ctype="TextFieldObjectData">
                <Position X="622.5" Y="233" />
                <Scale ScaleX="1" ScaleY="1" />
                <AnchorPoint ScaleX="0.4979533" ScaleY="0.5" />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="350" Y="60" />
                <PrePosition X="0.5479754" Y="0.3640625" />
                <PreSize X="0.3080986" Y="0.09375" />
              </NodeObjectData>
            </Children>
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1" />
          </NodeObjectData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>